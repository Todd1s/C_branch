#!/bin/bash

# Путь к исполняемому файлу cat
CAT_EXECUTABLE="./s21_cat"

# Путь к тестовым файлам
TEST_FILES=("zxc.txt" "zxccopy.txt")

test_b() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -b "$file")
        actual_output=$("$CAT_EXECUTABLE" -b "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -b ($file): успешно"
        else
            echo "Тест для команды cat -b ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_e() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -e "$file")
        actual_output=$("$CAT_EXECUTABLE" -e "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -e ($file): успешно"
        else
            echo "Тест для команды cat -e ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_n() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -n "$file")
        actual_output=$("$CAT_EXECUTABLE" -n "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -n ($file): успешно"
        else
            echo "Тест для команды cat -n ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_s() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -s "$file")
        actual_output=$("$CAT_EXECUTABLE" -s "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -s ($file): успешно"
        else
            echo "Тест для команды cat -s ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_t() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -t "$file")
        actual_output=$("$CAT_EXECUTABLE" -t "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -t ($file): успешно"
        else
            echo "Тест для команды cat -t ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_number_nonblank() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat --number-nonblank "$file")
        actual_output=$("$CAT_EXECUTABLE" --number-nonblank "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat --number-nonblank ($file): успешно"
        else
            echo "Тест для команды cat --number-nonblank ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_E() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -E "$file")
        actual_output=$("$CAT_EXECUTABLE" -E "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -E ($file): успешно"
        else
            echo "Тест для команды cat -E ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_number() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat --number "$file")
        actual_output=$("$CAT_EXECUTABLE" --number "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat --number ($file): успешно"
        else
            echo "Тест для команды cat --number ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_squeeze_blank() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat --squeeze-blank "$file")
        actual_output=$("$CAT_EXECUTABLE" --squeeze-blank "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat --squeeze-blank ($file): успешно"
        else
            echo "Тест для команды cat --squeeze-blank ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_T() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(cat -T "$file")
        actual_output=$("$CAT_EXECUTABLE" -T "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды cat -T ($file): успешно"
        else
            echo "Тест для команды cat -T ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

# Запуск тестов
test_b
test_e
test_n
test_s
test_t
# test_number_nonblank
# test_E
# test_number
# test_squeeze_blank
# test_T