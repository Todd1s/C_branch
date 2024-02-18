#include "../s21_decimal.h"

int setBit(unsigned int num, int pos) { return (num | ((unsigned)1 << pos)); }

int getBit(unsigned int num, int pos) {
  return ((num & ((unsigned)1 << pos)) >> pos);
}

int clearBit(unsigned int num, int pos) {
  return (num & (~((unsigned)1 << pos)));
}

int toggleBit(unsigned int num, int pos) {
  return (num ^ ((unsigned)1 << pos));
}

int get_exp(s21_decimal value) { return (value.bits[3] << 10) >> 26; }
int get_sign(s21_decimal value) { return (value.bits[3] >> 31) & 1; }

void equal_exponents(s21_decimal *value_1, s21_decimal *value_2) {
  int exp1 = get_exp(*value_1);
  int exp2 = get_exp(*value_2);
  int decreased = 10;
  int val_num = 2;
  int more_than_once = 0;
  while (exp1 != exp2) {
    if (exp2 > exp1) {
      if (!increase_exponent(value_1)) {
        decreased = decrease_exponent(value_2);
        exp2 = get_exp(*value_2);
        if (!more_than_once && val_num != 2) {
          more_than_once = 1;
        }
        val_num = 0;
      }
      exp1 = get_exp(*value_1);
    } else {
      if (!increase_exponent(value_2)) {
        decreased = decrease_exponent(value_1);
        exp1 = get_exp(*value_1);
        if (!more_than_once && val_num != 2) {
          more_than_once = 1;
        }
        val_num = 1;
      }
      exp2 = get_exp(*value_2);
    }
  }
  if (decreased < 10) {
    if (val_num) {
      if (((getBit(value_1->bits[0], 0) || more_than_once ||
            getBit(value_2->bits[0], 0)) &&
           (decreased == 5)) ||
          (decreased > 5) || (get_sign(*value_1) && decreased)) {
        s21_add(*value_1, (s21_decimal){{1, 0, 0, value_1->bits[3]}}, value_1);
      }
    } else {
      if (((getBit(value_2->bits[0], 0) || more_than_once ||
            getBit(value_1->bits[0], 0)) &&
           (decreased == 5)) ||
          (decreased > 5) || (get_sign(*value_2) && decreased)) {
        s21_add(*value_2, (s21_decimal){{1, 0, 0, value_2->bits[3]}}, value_2);
      }
    }
  }
}

int increase_exponent(s21_decimal *value) {
  int res = 1;
  s21_decimal temp = *value;
  if (!mul_by_10(&temp)) {
    *value = temp;
    value->bits[3] += (1 << 16);
  } else {
    res = 0;
  }
  return res;
}

int decrease_exponent(s21_decimal *value) {
  int last = div_by_10(*value, value, 0);
  value->bits[3] -= (1 << 16);
  return last;
}

int mul_by_10(s21_decimal *value) {
  int res = 0;
  s21_decimal value_2 = (s21_decimal){
      {value->bits[0] << 1, (value->bits[1] << 1) | getBit(value->bits[0], 31),
       (value->bits[2] << 1) | getBit(value->bits[1], 31), value->bits[3]}};
  s21_decimal value_8 = (s21_decimal){
      {value->bits[0] << 3, (value->bits[1] << 3) | (value->bits[0] >> 29),
       (value->bits[2] << 3) | (value->bits[1] >> 29), value->bits[3]}};
  if (!(value->bits[2] >> 28)) {
    s21_add(value_2, value_8, value);
  } else {
    res = 1;
  }
  return res;
}

int big_mul_by_10(s21_big_decimal *value) {
  int res = 0;
  s21_big_decimal value_2 = (s21_big_decimal){
      {value->bits[0] << 1, (value->bits[1] << 1) | getBit(value->bits[0], 31),
       (value->bits[2] << 1) | getBit(value->bits[1], 31),
       (value->bits[3] << 1) | getBit(value->bits[2], 31),
       (value->bits[4] << 1) | getBit(value->bits[3], 31),
       (value->bits[5] << 1) | getBit(value->bits[4], 31)},
      0};
  s21_big_decimal value_8 = (s21_big_decimal){
      {value->bits[0] << 3, (value->bits[1] << 3) | (value->bits[0] >> 29),
       (value->bits[2] << 3) | (value->bits[1] >> 29),
       (value->bits[3] << 3) | (value->bits[2] >> 29),
       (value->bits[4] << 3) | (value->bits[3] >> 29),
       (value->bits[5] << 3) | (value->bits[4] >> 29)},
      0};
  big_add(value_2, value_8, value);
  return res;
}

int basic_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              int *res) {
  int carry = 0;
  int default_sign = get_sign(value_1);
  for (int i = 0; i < 96; i++) {
    int bit1 = getBit(value_1.bits[i / 32], i % 32);
    int bit2 = getBit(value_2.bits[i / 32], i % 32);
    int sum = bit1 + bit2 + carry;
    carry = getBit(sum, 1);
    if (getBit(sum, 0)) {
      (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
    }
  }
  if (carry) {
    int last = div_by_10(*result, result, 1);
    if ((getBit(result->bits[0], 0) && (last == 5)) || (last > 5) ||
        (get_sign(*result) && last)) {
      s21_add(*result, (s21_decimal){{1, 0, 0, result->bits[3]}}, result);
    }
  }
  (*result).bits[3] =
      (unsigned)get_sign(value_1) << 31 | (get_exp(value_1) - carry) << 16;
  if (get_exp(*result) > 28) {
    *res = 1 + default_sign;
  }
  return carry;
}

void basic_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
               int *res) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  int default_sign = get_sign(value_1);
  for (int i = 0; i < 96; i++) {
    int bit1 = getBit(value_1.bits[i / 32], i % 32);
    int bit2 = getBit(value_2.bits[i / 32], i % 32);
    int sum;
    int current_bit = i;
    int flag = 0;
    while ((sum = (bit1 - bit2)) < 0) {
      if ((bit1 = getBit(value_1.bits[current_bit / 32], current_bit % 32))) {
        flag = 1;
        value_1.bits[current_bit / 32] =
            clearBit(value_1.bits[current_bit / 32], current_bit % 32);
        while (current_bit > i) {
          current_bit--;
          value_1.bits[current_bit / 32] =
              setBit(value_1.bits[current_bit / 32], current_bit % 32);
        }
      } else {
        current_bit++;
      }
    }
    if (flag || sum) {
      (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
    }
  }
  (*result).bits[3] = (unsigned)get_sign(value_1) << 31 | (get_exp(value_1))
                                                              << 16;
  if (get_exp(*result) > 28) {
    *res = 1 + default_sign;
  }
}

int long_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int exp = 0;
  *result = (s21_decimal){{0, 0, 0, 0}};
  s21_big_decimal long_result = (s21_big_decimal){{0, 0, 0, 0, 0, 0}, 0};
  big_mul(
      (s21_big_decimal){
          {value_1.bits[0], value_1.bits[1], value_1.bits[2], 0, 0, 0}, 0},
      (s21_big_decimal){
          {value_2.bits[0], value_2.bits[1], value_2.bits[2], 0, 0, 0}, 0},
      &long_result);
  exp = big_decimal_to_decimal(long_result, result);
  return exp;
}

int big_decimal_to_decimal(s21_big_decimal long_result, s21_decimal *result) {
  s21_big_decimal cpy = long_result;
  int exp = 0;
  int last = 0;
  while (cpy.bits[3] || cpy.bits[4] || cpy.bits[5]) {
    exp++;
    last = big_div_by_10(cpy, &cpy);
  }
  result->bits[0] = cpy.bits[0];
  result->bits[1] = cpy.bits[1];
  result->bits[2] = cpy.bits[2];
  if ((getBit(result->bits[0], 0) && (last == 5)) || (last > 5)) {
    s21_add(*result, (s21_decimal){{1, 0, 0, result->bits[3]}}, result);
  }
  return exp;
}

void big_add(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  *result = (s21_big_decimal){{0, 0, 0, 0, 0, 0}, 0};
  int carry = 0;
  for (int i = 0; i < 192; i++) {
    int bit1 = getBit(value_1.bits[i / 32], i % 32);
    int bit2 = getBit(value_2.bits[i / 32], i % 32);
    int sum = bit1 + bit2 + carry;
    carry = getBit(sum, 1);
    if (getBit(sum, 0)) {
      (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
    }
  }
}

void big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  *result = (s21_big_decimal){{0, 0, 0, 0, 0, 0}, 0};
  for (int i = 0; i < 96; i++) {
    int bit1 = getBit(value_1.bits[i / 32], i % 32);
    if (bit1) {
      s21_big_decimal value_to_add = value_2;
      for (int j = 0; j < i; j++) {
        big_shift(&value_to_add);
      }
      big_add(*result, value_to_add, result);
    }
  }
}

int overflow_check(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  int flag = 0;
  for (int i = 95; (i >= 0) && !flag; i--) {
    if (getBit(value_1.bits[i / 32], i % 32)) {
      flag = 1;
      res += i;
    }
  }
  flag = 0;
  for (int i = 95; (i >= 0) && !flag; i--) {
    if (getBit(value_2.bits[i / 32], i % 32)) {
      flag = 1;
      res += i;
    }
  }
  return res;
}

void basic_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  for (int i = 0; i < 96; i++) {
    int bit1 = getBit(value_1.bits[i / 32], i % 32);
    if (bit1) {
      s21_decimal value_to_add = value_2;
      for (int j = 0; j < i; j++) {
        shift(&value_to_add);
      }
      value_to_add.bits[3] = 0;
      s21_add(*result, value_to_add, result);
    }
  }
}

int big_div_by_10(s21_big_decimal value, s21_big_decimal *result) {
  unsigned long buf1 = 0;
  unsigned long buf2 = 0;
  unsigned long buf3 = 0;
  unsigned long buf4 = 0;
  unsigned long buf5 = 0;
  result->bits[5] = value.bits[5] / 10;
  buf1 =
      ((unsigned long)value.bits[5] % 10) * ((unsigned long)__UINT32_MAX__ + 1);
  result->bits[4] = (((unsigned long)value.bits[4] + buf1) / 10);
  buf2 = (((unsigned long)value.bits[4] + buf1) % 10) *
         ((unsigned long)__UINT32_MAX__ + 1);
  result->bits[3] = (((unsigned long)value.bits[3] + buf2) / 10);
  buf3 = (((unsigned long)value.bits[3] + buf2) % 10) *
         ((unsigned long)__UINT32_MAX__ + 1);
  result->bits[2] = ((unsigned long)value.bits[2] + buf3) / 10;
  buf4 = (((unsigned long)value.bits[2] + buf3) % 10) *
         ((unsigned long)__UINT32_MAX__ + 1);
  result->bits[1] = (((unsigned long)value.bits[1] + buf4) / 10);
  buf5 = (((unsigned long)value.bits[1] + buf4) % 10) *
         ((unsigned long)__UINT32_MAX__ + 1);
  result->bits[0] = (((unsigned long)value.bits[0] + buf5) / 10);
  return ((unsigned long)value.bits[0] + buf5) % 10;
}

int div_by_10(s21_decimal value, s21_decimal *result, int carry) {
  unsigned long buf1 = 0;
  unsigned long buf2 = 0;
  result->bits[2] = ((unsigned long)value.bits[2] +
                     carry * ((unsigned long)__UINT32_MAX__ + 1)) /
                    10;
  buf1 = (((unsigned long)value.bits[2] +
           carry * ((unsigned long)__UINT32_MAX__ + 1)) %
          10) *
         ((unsigned long)__UINT32_MAX__ + 1);

  result->bits[1] = (((unsigned long)value.bits[1] + buf1) / 10);
  buf2 = (((unsigned long)value.bits[1] + buf1) % 10) *
         ((unsigned long)__UINT32_MAX__ + 1);

  result->bits[0] = (((unsigned long)value.bits[0] + buf2) / 10);
  return ((unsigned long)value.bits[0] + buf2) % 10;
}

int remainder_div(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  int cur_exp = get_exp(value_1) - get_exp(value_2);
  int max_shift = 0;
  for (int i = 95; i >= 0 && !max_shift; i--) {
    if (getBit(value_2.bits[i / 32], i % 32)) {
      max_shift = 96 - i;
    }
  }
  *result = (s21_decimal){{0, 0, 0, 0}};
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;
  while (s21_is_greater_or_equal(value_1, value_2)) {
    s21_decimal value_to_add = value_2;
    s21_decimal tmp = value_2;
    int q = 0;
    while (s21_is_greater_or_equal(value_1, value_to_add) && q < max_shift &&
           !getBit(result->bits[2], 31)) {  // b*2^q<=a
      shift(&value_to_add);
      if (q != 0) {
        shift(&tmp);
      }
      q++;
    }
    value_to_add = (s21_decimal){{0, 0, 0, 0}};
    value_to_add.bits[(q - 1) / 32] = ((unsigned)1 << ((q - 1) % 32));
    s21_add(*result, value_to_add, result);
    s21_sub(value_1, tmp, &value_1);
    while (!(is_zero(value_1)) && s21_is_less(value_1, value_2) &&
           (cur_exp < 28) && (!(result->bits[2] >> 28))) {
      mul_by_10(&value_1);
      mul_by_10(result);
      cur_exp++;
    }
  }
  if ((result->bits[2] >> 28) || (cur_exp >= 28)) {
    round_after_division(result, &cur_exp, max_shift, value_1, value_2);
  }
  result->bits[3] = 0;
  return cur_exp;
}

void round_after_division(s21_decimal *result, int *cur_exp, int max_shift,
                          s21_decimal value_1, s21_decimal value_2) {
  s21_decimal copy = *result;
  s21_big_decimal big_result = (s21_big_decimal){
      {result->bits[0], result->bits[1], result->bits[2], 0, 0}, 0};
  for (int i = 0; i <= 28 - *cur_exp; i++) {
    mul_by_10(&value_1);
    big_mul_by_10(&big_result);
  }
  while (s21_is_greater_or_equal(value_1, value_2)) {
    s21_decimal value_to_add = value_2;
    s21_decimal tmp = value_2;
    int q = 0;
    while (s21_is_greater_or_equal(value_1, value_to_add) && q < max_shift &&
           !getBit(result->bits[2], 31)) {
      shift(&value_to_add);
      if (q != 0) {
        shift(&tmp);
      }
      q++;
    }
    s21_big_decimal value = (s21_big_decimal){{0, 0, 0, 0, 0, 0}, 0};
    value.bits[(q - 1) / 32] = ((unsigned)1 << ((q - 1) % 32));
    big_add(big_result, value, &big_result);
    s21_sub(value_1, tmp, &value_1);
  }
  int exp = big_decimal_to_decimal(big_result, result);
  if (*cur_exp == 28 && (exp == (28 - *cur_exp))) {
    int last = div_by_10(*result, result, 0);
    if ((getBit(result->bits[0], 0) && (last == 5)) || (last > 5) ||
        (get_sign(*result) && last)) {
      s21_add(*result, (s21_decimal){{1, 0, 0, result->bits[3]}}, result);
    }
  }
  if (copy.bits[2] != result->bits[2]) {
    (*cur_exp)++;
  }
}

void big_shift(s21_big_decimal *value) {
  *value = (s21_big_decimal){
      {value->bits[0] << 1, (value->bits[1] << 1) | (value->bits[0] >> 31),
       (value->bits[2] << 1) | (value->bits[1] >> 31),
       (value->bits[3] << 1) | (value->bits[2] >> 31),
       (value->bits[4] << 1) | (value->bits[3] >> 31),
       (value->bits[5] << 1) | (value->bits[4] >> 31)},
      value->exp};
}

void shift(s21_decimal *value) {
  *value = (s21_decimal){
      {value->bits[0] << 1, (value->bits[1] << 1) | (value->bits[0] >> 31),
       (value->bits[2] << 1) | (value->bits[1] >> 31), value->bits[3]}};
}

void set_bit(unsigned int *destination, unsigned int position,
             unsigned int value) {
  if (value)
    *destination |= ((unsigned)1 << position);
  else
    *destination &= ~((unsigned)1 << position);
}

int is_zero(s21_decimal value) {
  return (!value.bits[0] && !value.bits[1] && !value.bits[2]) ? 1 : 0;
}

void decimal_to_big_decimal(s21_decimal from, s21_big_decimal *to) {
  for (int i = 0; i < 3; i++) {
    to->bits[i] = from.bits[i];
  }
  to->bits[3] = 0;
  to->bits[4] = 0;
  to->bits[5] = 0;
  to->exp = get_exp(from);
}

void shift_right(s21_decimal *value) {
  int store_bit = 0;
  for (int i = 2; i >= 0; i--) {
    int new_bit = getBit(value->bits[i], 0);
    value->bits[i] = value->bits[i] >> 1;
    set_bit(&(value->bits[i]), 31, store_bit);
    store_bit = new_bit;
  }
}

void shift_big_decimal_left(s21_big_decimal *value) {
  int store_bit = 0;
  for (int i = 0; i < 6; i++) {
    int new_bit = getBit(value->bits[i], 31);
    value->bits[i] = value->bits[i] << 1;
    set_bit(&(value->bits[i]), 31, store_bit);
    store_bit = new_bit;
  }
}

int add_for_multiply(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  int check = 0;
  int store_bit = 0;
  for (int i = 0; i < 192; i++) {
    int a = getBit(value_2.bits[i / 32], i % 32);
    int b = getBit(value_1.bits[i / 32], i % 32);
    set_bit(&(result->bits[i / 32]), i % 32, a ^ b ^ store_bit);
    store_bit = (a && b) || (b && store_bit) || (a && store_bit);
  }
  if (store_bit) check = 1;
  return check;
}

int multiply_10_big(s21_big_decimal *src) {
  s21_big_decimal result = {{0}, 0};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  int check = 0;
  s21_big_decimal tmp_1 = *src;
  while (!is_zero(value_2) && !check) {
    if (getBit(value_2.bits[0], 0))
      check = add_for_multiply(result, tmp_1, &result);
    shift_big_decimal_left(&tmp_1);
    if (getBit(result.bits[5], 31)) check = 1;
    shift_right(&value_2);
  }
  result.exp = src->exp;
  *src = result;
  return check;
}

int count_digits(long n) {
  int count = 0;
  if (n < 0) {
    n *= -1;
  }
  while (n >= 1) {
    n /= 10;
    count++;
  }
  return count;
}

void nulify_dec(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

int normalize_big(s21_big_decimal *x1, s21_big_decimal *x2) {
  int check = 0;
  s21_big_decimal *x_fix;
  int diff = 0;
  if (x1->exp <= x2->exp) {
    x_fix = x1;
    diff = x2->exp - x1->exp;
  } else {
    x_fix = x2;
    diff = x1->exp - x2->exp;
  }
  while (diff--) {
    check = multiply_10_big(x_fix);
    if (check) break;
    x_fix->exp += 1;
  }
  return check;
}
