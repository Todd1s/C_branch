#!/bin/bash

# Путь к исполняемому файлу grep
GREP_EXECUTABLE="./s21_grep"

# Путь к тестовым файлам
TEST_FILES=("zxc.txt" "zxccopy.txt")

pattern="My" # Универсальный шаблон

test_e() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -e "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -e "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -e ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -e ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_i() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -i "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -i "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -i ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -i ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_v() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -v "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -v "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -v ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -v ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_c() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -c "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -c "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -c ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -c ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_l() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -l "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -l "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -l ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -l ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

test_n() {
    for file in "${TEST_FILES[@]}"; do
        expected_output=$(grep -n "$pattern" "$file")
        actual_output=$("$GREP_EXECUTABLE" -n "$pattern" "$file")
        # Сравнение ожидаемого и фактического вывода
        if [[ "$expected_output" == "$actual_output" ]]; then
            echo "Тест для команды grep -n ($pattern) ($file): успешно"
        else
            echo "Тест для команды grep -n ($pattern) ($file): провал"
            echo "Расхождения:"
            diff <(echo "$expected_output") <(echo "$actual_output")
        fi
    done
}

# Запуск тестов
test_e
test_i
test_v
test_c
test_l
test_n