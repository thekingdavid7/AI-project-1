# Compiler
CXX = g++

# Executable name
CXXFLAGS = -std=c++11 -Wall -Wextra

.PHONY: clean

connectM: connectM.o boardView.o game.o aiLogic.o
	$(CXX) $(CXXFLAGS) connectM.o boardView.o game.o aiLogic.o -o connectM

connectM.o: connectM.cpp boardView.hpp game.hpp aiLogic.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

boardView.o: boardView.cpp boardView.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

game.o: game.cpp game.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

aiLogic.o: aiLogic.cpp aiLogic.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o connectM