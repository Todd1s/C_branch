.PHONY: all build static install uninstall rebuild dist test gcov_report clean
CC=gcc
CFLAGS= -Wall -Wextra -Werror -std=c11

FLAGS_TEST_LIBS =

SRC=SmartCalcMain.c
NAME=SmartCalcMain.a
OBJ=$(patsubst %.c, %.o, $(SRC))
OS = $(shell uname)

ifeq ($(OS), Darwin)
	FLAGS_TEST_LIBS = -lpthread -lcheck -lm 
else ($(OS), Linux)
	FLAGS_TEST_LIBS = -lm -lcheck -lsubunit -pedantic
endif

all: build static

install:
	make clean
	mkdir build
	cd SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && \
    if [ -d SmartCalc/SmartCalc.app ]; then \
        mv SmartCalc/SmartCalc.app build/; \
    else \
        mv SmartCalc/SmartCalc build/; \
    fi

uninstall:
	rm -rf build*

clean:
	cd SmartCalc && rm -rf *.a && rm -rf *.o  && rm -rf *.dSYM && rm -rf *.out && rm -rf $(EXECUTABLE) && rm -rf gcov_report && rm -rf report && rm -rf CPPLINT.cfg && rm -rf *.gcda 
	cd SmartCalc && rm -rf *.gcno && rm -rf *.info && rm -rf test && rm -rf Dist_SmartCalc && rm -rf *tgz && rm -rf build && rm -rf SC_test && rm -rf gcov_test && rm -rf .qmake.stash && rm -rf SmartCalc.pro.user

dvi:
	open README.txt

dist: uninstall install
	rm -rf Dist_SmartCalc/
	mkdir Dist_SmartCalc/
	mkdir Dist_SmartCalc/src
	mv ./build/SmartCalc.app Dist_SmartCalc/src/
	tar cvzf Dist_SmartCalc.tgz Dist_SmartCalc/
	rm -rf Dist_SmartCalc/
	rmdir build

test: clean 
	cd SmartCalc && gcc $(GCOVFLAGS) SmartCalcMain.c test.c  $(FLAGS_TEST_LIBS) -o test -lcheck
	cd SmartCalc && ./test

gcov_report: all
	cd SmartCalc && $(CC) $(CFLAGS) --coverage test.c $(SRC) $(NAME) $(FLAGS_TEST_LIBS) -o gcov_test
	cd SmartCalc && chmod +x *
	cd SmartCalc && ./gcov_test
	cd SmartCalc && lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	cd SmartCalc && genhtml -o report/ gcov_test.info
	cd SmartCalc && open ./report/index.html

build:
	cd SmartCalc && $(CC) $(CFLAGS) -c $(SRC)

static:
	cd SmartCalc && ar rc $(NAME) $(OBJ)
	cd SmartCalc && ranlib $(NAME)

rebuild: uninstall clean install
	
clang:
	cd SmartCalc && clang-format -style=Google -n *.c *.h *.cpp && clang-format -style=Google -i *.c *.h *.cpp

run:
ifeq ($(OS), Darwin)
	build/SmartCalc.app/Contents/MacOS/SmartCalc
else
	build/SmartCalc
endif