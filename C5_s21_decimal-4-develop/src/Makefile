CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_DIR = building
FUNCTIONS_DIR = functions
TESTS_DIR = tests
COVERAGE = 
LIB_NAME = s21_decimal.a

SRCS = $(wildcard $(FUNCTIONS_DIR)/*.c)
OBJS = $(patsubst $(FUNCTIONS_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c)
TEST_EXECUTABLES = $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/%,$(TEST_SRCS))

ifeq ($(shell uname -s),Linux)
LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread $(COVERAGE)
endif
ifeq ($(shell uname -s),Darwin)
LDFLAGS=-lcheck -lm -lpthread $(COVERAGE)
endif

all: clang $(LIB_NAME) $(TEST_EXECUTABLES)

$(LIB_NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(BUILD_DIR)/%.o: $(FUNCTIONS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/%: $(TESTS_DIR)/%.c $(LIB_NAME)
	$(CC) $(CFLAGS) -I. $< $(LIB_NAME) -o $@ $(LDFLAGS)
	

clean:
	rm -rf *.a $(BUILD_DIR)/* $(TESTS_DIR)/*.o tests.info report gcov .clang-format *.gcno *.gcda

gcov_report: clean add_coverage test
	lcov -o tests.info -c -d ./
	genhtml -o gcov tests.info
	open gcov/index.html

add_coverage:
	$(eval COVERAGE += -fprofile-arcs -ftest-coverage --coverage)

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.h functions/*.c tests/*.c
	clang-format -i *.h functions/*.c tests/*.c

test: $(BUILD_DIR) $(TEST_EXECUTABLES)
	@for test in $(TEST_EXECUTABLES); do \
		$$test || true; \
	done
