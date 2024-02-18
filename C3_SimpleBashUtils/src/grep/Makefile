all: s21_grep

s21_grep: s21_grep.o s21_grep_function.o
	gcc -Wall -Werror -Wextra -o s21_grep s21_grep.o s21_grep_function.o
	rm -f *.o
	chmod +x grep_tests.sh 

s21_grep.o: s21_grep.h s21_grep.c
	gcc -Wall -Werror -Wextra -c s21_grep.c

s21_grep_function.o: s21_grep_function.c
	gcc -Wall -Werror -Wextra -c s21_grep_function.c

clean: 
	rm -f s21_grep

rebuild:
	make clean
	make all