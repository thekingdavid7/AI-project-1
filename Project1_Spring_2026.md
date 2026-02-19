# Document converted from PDF

**Total Pages:** 4

---

## Page 1

CAP 4601 Project 1: Adversarial Search Spring 2026

1

CONNECT M COMPUTER GAME

OVERVIEW

This assignment will require you to implement a computer game for a human user to play Connect M against a

machine. Your program must use adversarial search techniques, specifically alpha-beta pruning, along with a min

and max function to evaluate a game tree and select moves in the game to win it.

THE PROGRAM

Implement a program connectM in Java, C, C++, or Python. In this game, two players drop colored discs into a grid

of columns and rows from the top. The goal is to connect contiguously M disks of the same color across the rows

and columns in the grid either horizontally, vertically, or diagonally. The first player that connects all M disks

contiguously wins the game. If, at any point, it is no longer possible to connect M disks in the grid due to a lack of

space for disks, the game ends with no winner.

The program requires two input parameters that define the size of the grid as a quadratic board (note that the

original Connect Four board is not a quadratic grid) and the number of disks to connect contiguously. Your program

must be started from the command line according to the following syntax:

connectM N M H

Here, parameter N is the number of columns and rows in the N x N grid, M is the number of disks that must be

connected contiguously in the grid, and H is a flag that indicates if the human or computer makes the first move in

the game. The grid size should be at least three and no larger than 10. Parameter M must be higher than one but no

higher than N. Parameter H must be 1 or 0 if the human or computer makes the first move, respectively. Your

computer program will automatically choose a disk color/shape for the human and computer player.

Once the program starts, it prompts the human player to make a move by choosing a column to add a disk to the

board. Column information is entered as a number ranging from 1 to N. Finally, your program checks for winning

moves and terminates when it detects a winner or a draw.

DATA STRUCTURES

You must choose appropriate data structures to represent the board and state information about the game. You

must describe these data structures in the project report.

VISUALIZATION

Your program must use a two-dimensional visualization to show the board and its pieces. The visualization may be

a graphical user interface or a text-based user interface. If the visualization is text-based, choose simple ASCII

characters rather than colors to represent the two types of disks in the game. Below is a simple ASCII character-

based grid visualization illustrating two players with X and O as the two disk pieces.

---

## Page 2

CAP 4601 Project 1: Adversarial Search Spring 2026

2

+---+---+---+---+---+

| | | | | |

+---+---+---+---+---+

| | | X | O | |

+---+---+---+---+---+

| X | X | O | X | X |

+---+---+---+---+---+

| X | O | O | O | X |

+---+---+---+---+---+

| O | O | O | X | X |

+---+---+---+---+---+

DELIVERABLES

Your project submission should follow the instructions below. Any submissions that do not follow the stated

requirements will not be graded.

1. Follow the submission requirements of your instructor, as published in Canvas under the first module.

2. You should have, at a minimum, the following files for this assignment:

a. source code for the program in C, C++, Java, or Python

b. Makefile (if the program is implemented in C or C++)

c. README (instructions to compile the program and run it)

d. Report (PDF only)

You should use appropriate code refactoring techniques to improve the readability and maintainability of your code.

Your program will be evaluated according to the steps shown below. Notice that I will not fix your syntax or runtime

errors. However, they will make grading quick!

1. Program compilation with a Makefile in C or C++ or javac.

• If errors occur during compilation or if the program crashes during execution, there will be a

substantial deduction. The instructor will not fix your code to get it to compile.

2. Perform several evaluations with the input of the grader's choosing. At a minimum, the tests will answer

the following questions.

• Is a board visualized according to the input parameter?

• Are disks set correctly in the game for the player and the computer?

• Is a winning move recognized?

• Does the computer attempt to play a winning game?

REPORT

The report is a PDF-converted document that must contain the following information:

• a description of the agent model that closely matches your computer program

• a description of the agent environment in which your agent operates

• a description of the data structures used in the code

• a description of the code that implements the alpha-beta pruning algorithm

• a description of the heuristic evaluation functions that evaluate a move in the game

Base your description of the agent environment and model on those discussed in class. The report should be concise

yet detailed enough so that any programmer can take the description of your program to replicate your work. The

---

## Page 3

CAP 4601 Project 1: Adversarial Search Spring 2026

3

report may include screenshots, diagrams, and any illustrations. A template for writing your report is provided in

Canvas.

DUE DATE

The project is due as indicated in the schedule in the syllabus and calendar in Canvas. Upload your complete solution

to the Canvas dropbox as a zip file. I will not accept emailed submissions. Upload ahead of time, as last-minute

uploads may fail.

GRADING

This project is worth 100 points in total. The rubric used for grading is included below. Remember that there will be

deductions if your code does not compile or crashes or is otherwise poorly documented or organized.

Project Submission Perfect Deficient

Canvas

5 points

zip file has been

uploaded

0 points

nothing is uploaded

Compilation/

Execution

Perfect Good Deficient

README

5 points

clear instructions

provided

3 points

missing or unclear

instructions

0 points

README is missing

compilation

10 points

no errors, no

warnings

7 points

some warnings

0 points

errors

program execution

10 points

runs, no crashes,

accepts input, no

memory leaks

3 pts

runs, no crashes,

accepts input, some

memory leaks

0 pts

crashes or fails to

accept user input

Documentation &

Program Structure

Perfect Good Attempted Deficient

documentation &

program structure

5 points

follows

documentation and

code structure

guidelines

3 points

follows mostly

documentation and

code structure

guidelines; minor

deviations

2 points

some

documentation

and/or code

structure lacks

consistency

0 points

documentation is

missing or

insufficient; code

structure is poor;

review sample code

and guidelines

Program Perfect Good Attempted Deficient

board visualization

10 points

correct, completed

7 points

minor errors

3 points

incomplete

0 points

missing or does not

compile or run

correct player moves

10 points

correct, completed

7 points

minor errors

3 points

incomplete

0 points

missing or does not

compile or run

program uses alpha-beta

pruning algorithms – tree

structure may not be

needed

20 points

correct, completed

15 points

minor errors

5 points

incomplete

0 points

missing or does not

compile or run

program uses an

effective evaluation

function

15 points

correct, completed

11 points

minor errors

4 points

incomplete

0 points

missing or does not

compile or run

---

## Page 4

CAP 4601 Project 1: Adversarial Search Spring 2026

4

Reporting Perfect Good Attempted Deficient

discusses agent model &

environment, data

structures, impl. of

alpha-beta pruning

algorithm, and evaluation

function

10 points

completed

7 points

some information is

missing

3 points

mostly incomplete

0 points

missing

I will evaluate your solution as insufficient if your code does not compile or crashes immediately. This means if you

submit your solution according to my instructions, document and structure your source code as outlined in the

guidelines, and provide a README, but the submit code does not compile or crashes after I start it up, you can expect

at most between 25 to 35 out of 100 points. So be sure your code compiles and executes.

