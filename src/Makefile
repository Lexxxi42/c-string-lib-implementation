CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = $(shell find . -name "*.c" -not -path "*/test*" -not -name "*test*")
TSOURCES = $(shell find test -name "*test*.c")

OBJ = $(SOURCES:.c=.o)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: string.a

string.a: $(OBJ)
	@ar rc string.a $(OBJ)
	@ranlib string.a

test: clean
	@mkdir -p report
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) -o report/test_run $(TSOURCES) $(SOURCES) $(LDFLAGS) -lgcov
	@./report/test_run

style_check:
	find . -type f -name "*.h" -o -name "*.c" | xargs clang-format -n --

format:
	@find . -type f -name "*.h" -o -name "*.c" | xargs clang-format -i --

gcov_report: test
	@mkdir -p report
#	сбор данных покрытия
	lcov -c -d report --output-file report/coverage.info --exclude 'test/*'
#	генерация html
	genhtml -o report report/coverage.info
	@echo "Open report/index.html"

clean:
	@rm -f test_runner coverage.info
	@find .. -type f \( -name "*.o" -o -name "*.a" -o -name "*.gcno" -o -name "*.gcda" -o -name "*.gcov" \) -delete 2>/dev/null || true
	@rm -rf report
	@rm -f *.gcov

.PHONY: all string.a test style_check format gcov_report clean