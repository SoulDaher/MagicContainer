CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
INCLUDES = -Iinclude
TEST_SRC = tests/test.cpp
MAIN_SRC = main.cpp
EXEC_TEST = test_exec
EXEC_MAIN = main_exec

all: main test

main: $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(EXEC_MAIN) $(MAIN_SRC)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(EXEC_TEST) $(TEST_SRC)

run_test: test
	./$(EXEC_TEST)

valgrind: test
	valgrind --leak-check=full ./$(EXEC_TEST)

clean:
	rm -f $(EXEC_TEST) $(EXEC_MAIN)
