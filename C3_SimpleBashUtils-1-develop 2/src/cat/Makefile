all: s21_cat

s21_cat: s21_cat.o s21_cat_function.o
	gcc -Wall -Werror -Wextra -o s21_cat s21_cat.o s21_cat_function.o
	rm -f *.o
	chmod +x cat_tests.sh

s21_cat.o: s21_cat.h s21_cat.c
	gcc -Wall -Werror -Wextra -c s21_cat.c

s21_cat_function.o: s21_cat_function.c
	gcc -Wall -Werror -Wextra -c s21_cat_function.c

clean:
	rm -f s21_cat

rebuild:
	make clean
	make all
