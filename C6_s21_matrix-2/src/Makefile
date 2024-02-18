CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILD_DIR = .
FUNCTIONS_DIR = s21_functions
TESTS_DIR = s21_tests
COVERAGE = 
LIB_NAME = s21_matrix.a



SRCS = $(wildcard $(FUNCTIONS_DIR)/*.c) #Поиск файлов в каталоге с расширением .с
OBJS = $(patsubst $(FUNCTIONS_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS)) #Берет каждый элемент списка $(SRCS), который представляет исходные файлы в каталоге FUNCTIONS_DIR, и заменяет его на соответствующий объектный файл в каталоге BUILD_DIR, при этом сохраняя то же имя файла, но с расширением .o.
TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c) #Поиск файлов в каталоге с расширением .с
TEST_EXECUTABLES = $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/%,$(TEST_SRCS)) #Берет каждый элемент списка $(TEST_SRCS), который представляет исходные файлы в каталоге TESTS_DIR, и заменяет его на соответствующий объектный файл в каталоге BUILD_DIR, при этом сохраняя то же имя файла, но с расширением .o.

ifeq ($(shell uname -s),Linux)
LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread $(COVERAGE)
endif
ifeq ($(shell uname -s),Darwin)
LDFLAGS=-lcheck -lm -lpthread $(COVERAGE)
endif

all: clean clang $(LIB_NAME) $(TEST_EXECUTABLES) 


$(LIB_NAME): $(OBJS) #создание библиотеки $@(ссылка на цель LIB_NAME) из файлов $(OBJS) при помощи архиватора ar и опций rcs r- заменить, с- создать, s- создать индекс библиотеки
	ar rcs $@ $(OBJS) 
	rm -rf *.o

$(BUILD_DIR)/%.o: $(FUNCTIONS_DIR)/%.c #компляция объектных файлов из $<(ссылка на первую зависимость $(FUNCTIONS_DIR)/%.c) в объектный с навзанием $@ + флаги в %(путь)
	$(CC) $(CFLAGS) -c $< -o $@ $(COVERAGE)

$(BUILD_DIR)/%: $(TESTS_DIR)/%.c $(LIB_NAME) #компиляция тестовых объектных с использованием библиотеки
	$(CC) $(CFLAGS) -I. $< $(LIB_NAME) -o $@ $(LDFLAGS)

clean:
	rm -rf *.o *.a s21_test_* *.info *.gcda *.gcno 
	rm -rf gcov

gcov_report: clean add_coverage test $(LIB_NAME)
	lcov -o tests.info -c -d .
	genhtml -o gcov tests.info
	open gcov/index.html
	rm -rf s21_test_* *.a *.info *.gcda *.gcno

add_coverage:
	$(eval COVERAGE += -fprofile-arcs -ftest-coverage --coverage)

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.h s21_functions/*.c s21_tests/*.c
	clang-format -i *.h s21_functions/*.c s21_tests/*.c
	rm -rf .clang-format

test: $(BUILD_DIR) $(TEST_EXECUTABLES) # проверяет начиличе папок зависимостей, начинает цикл, в котором запускаются исполняемые файлы, если они вывдает ошибку, цикл выаполняется дальше
	@for test in $(TEST_EXECUTABLES); do \
		$$test || true; \
	done
	rm -rf s21_test_* *.a 
