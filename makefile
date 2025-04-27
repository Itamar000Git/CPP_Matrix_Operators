#itamarbabai98@gmail.com
C = g++

HEADERS =squareMath.hpp doctest.h rows.hpp
Target = main
TEST_TARGET = Test_prog
FLAGS = -c -g -Wall
OBJECT = squareMath.o main.o
TEST_OBJ = squareMath.o test_prog.o

$(Target): $(OBJECT)
	$(C) -Wall -o $(Target) $(OBJECT)

$(TEST_TARGET): $(TEST_OBJ)
	$(C) -Wall -o $(TEST_TARGET) $(TEST_OBJ)

squareMath.o: squareMath.cpp $(HEADERS)
	$(C) $(FLAGS) squareMath.cpp -o squareMath.o

main.o: main.cpp $(HEADERS)
	$(C) $(FLAGS) main.cpp -o main.o

test_prog.o:test_prog.cpp $(HEADERS)
	$(C) $(FLAGS) test_prog.cpp -o test_prog.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)

Main: $(Target)
	./$(Target)

valgrind: $(Target)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(Target)

valgrind_tests: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

.PHONY: $(Target) clean

clean:
	rm -f $(PATH_CPP)*.o $(Target) $(TEST_TARGET)

