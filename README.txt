README
HOW TO START THE GAME:
Open VSCode
Open  git bash terminal
Clone the github repository into VSCode
	git clone https://github.com/thekingdavid7/AI-project-1.git
Open Ubuntu (WSL) terminal
To compile, type
	make
To run the program, type this, where
N = rows/cols,
M = how many in a row to win, and
H = human or computer player first (1 or 0)
	./connectM N M H
	./connectM 4 3 1
To clean up the object files, type
	Make clean
PLAYING THE GAME
It will display the board at the start of the game
If it is the computer’s turn, it will show the computer taking a move
If it is your turn, it will ask you for your move
Type the column you want to drop a piece into
	2
If it is an invalid choice, it will ask you to choose again
If you want to exit the game, type -1
	-1
