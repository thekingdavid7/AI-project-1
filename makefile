# Compiler
CXX = g++

# Executable name
CXXFLAGS = -std=c++11 -Wall -Wextra

.PHONY: clean

connectM: connectM.o boardView.o
	$(CXX) $(CXXFLAGS) connectM.o boardView.o -o connectM

connectM.o: connectM.cpp boardView.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

boardView.o: boardView.cpp boardView.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# main: main.o geneticAlgorithm.o
# 	$(CXX) $(CXXFLAGS) main.o geneticAlgorithm.o -o main

# main.o: main.cpp geneticAlgorithm.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# geneticAlgorithm.o: geneticAlgorithm.cpp geneticAlgorithm.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o connectM