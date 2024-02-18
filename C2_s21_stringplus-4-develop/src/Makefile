CC = gcc
FLAGS = -Wall -Werror -Wextra -g
OBJ = s21_base_func.o s21_bonus_func.o s21_sprintf.o s21_sscanf.o
LIBS = -L/opt/homebrew/lib -lcheck
RM_OBJ = rm -f *.o

UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck_pic -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

all: s21_string.a

s21_string: clean $(OBJ)
	$(CC) $(FLAGS) -o s21_string $(OBJ) $(LIBS)
	$(RM_OBJ)

s21_base_func.o: s21_string.h s21_base_func.c
	$(CC) $(FLAGS) -c s21_base_func.c

s21_bonus_func.o: s21_string.h s21_bonus_func.c
	$(CC) $(FLAGS) -c s21_bonus_func.c

s21_sprintf.o: s21_string.h s21_sprintf.c s21_libs.c
	$(CC) $(FLAGS) -c s21_sprintf.c s21_libs.c

s21_sscanf.o: s21_string.h s21_sscanf.c
	$(CC) $(FLAGS) -c s21_sscanf.c

clean: 
	rm -fr *.o *.gcno *.gcda s21_string s21_string.a test report gcov_report *.info



test: clean test.o $(OBJ)
	$(CC) $(FLAGS) -o test *.o $(LDFLAGS)
	$(RM_OBJ)
	./test

test.o: s21_string.h ./our_tests/s21_test.h ./our_tests/*.c s21_base_func.c s21_bonus_func.c s21_sprintf.c s21_libs.c s21_sscanf.c
	$(CC) $(FLAGS) -c ./our_tests/*.c s21_base_func.c s21_bonus_func.c s21_sprintf.c s21_libs.c s21_sscanf.c



s21_string.a: clean $(OBJ)
	ar rcs s21_string.a $(OBJ)
	$(RM_OBJ)

gcov_report: clean $(OBJ) gcov_report.o test.o
	$(CC) $(FLAGS) --coverage -o test *.o $(LIBS)
	$(CC) $(FLAGS) --coverage -c *.c
	$(CC) $(FLAGS) --coverage -o gcov_report *.o $(LIBS)
	./gcov_report
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	$(RM_OBJ) *.info *.gcno *.gcda gcov_report test
	open ./report/index.html

gcov_report.o: s21_string.h ./our_tests/s21_test.h ./our_tests/*.c 
	$(CC) $(FLAGS) --coverage -c ./our_tests/*.c 
	

rebuild: 
	make clean
	make all
	make s21_string.a
	make test

cln:
	cp ../materials/linters/.clang-format ./
	clang-format -n *c *.h
	rm -rf .clang-format

cli:
	cp ../materials/linters/.clang-format ./
	clang-format -i *c *.h
	rm -rf .clang-format


