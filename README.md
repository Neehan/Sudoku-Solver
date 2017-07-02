Sudoku-Solver
==============
[![Build Status](https://travis-ci.org/Neehan/Sudoku-Solver.svg?branch=master)](https://travis-ci.org/Neehan/Sudoku-Solver)
This is a very fast sudoku solver that solves most sudokus under 1 millisecond. 

How to install
---------------
Download [the latest release](http://www.github.com/Neehan/Sudoku-Solver/releases) of `Sudoku-Solver`, and run it. Alternatively, you can run the [`Makefile`](Makefile) to build from source. 

How to use
-----------
Feed this program your sudoku from `stdinput`. Blank cells has to be replaced by either `0` or `.`. The program will discard all other characters and wait until 81 valid inputs (for 81 cells of your sudoku) have been provided.

Example
--------
Let us solve the following sudoku with `Sudoku-Solver`.
```
+-------+-------+-------+
| 1 . . | 9 2 . | . . . |
| 5 2 4 | . 1 . | . . . |
| . . . | . . . | . 7 . |
+-------+-------+-------+
| . 5 . | . . 8 | 1 . . |
| . . . | . . . | . . . |
| 4 . 2 | 7 . . | . 9 . |
+-------+-------+-------+
| . 6 . | . . . | . . . |
| . . . | . 3 . | 9 4 5 |
| . . . | . 7 1 | . . 6 |
+-------+-------+-------+
```
**Note: The given sudoku must have _at least_ one solution.**
## Input
```
1 . . 9 2 . . . .
5 2 4 . 1 . . . .
. . . . . . . 7 .
. 5 . . . 8 1 . .
. . . . . . . . .
4 . 2 7 . . . 9 .
. 6 . . . . . . .
. . . . 3 . 9 4 5
. . . . 7 1 . . 6
```
## Output
```
+-------+-------+-------+
| 1 7 8 | 9 2 6 | 4 5 3 |
| 5 2 4 | 3 1 7 | 8 6 9 |
| 9 3 6 | 8 4 5 | 2 7 1 |
+-------+-------+-------+
| 6 5 7 | 2 9 8 | 1 3 4 |
| 8 9 3 | 1 6 4 | 5 2 7 |
| 4 1 2 | 7 5 3 | 6 9 8 |
+-------+-------+-------+
| 3 6 5 | 4 8 9 | 7 1 2 |
| 7 8 1 | 6 3 2 | 9 4 5 |
| 2 4 9 | 5 7 1 | 3 8 6 |
+-------+-------+-------+

Execution time: 0.000593 s
```
## License
This software is  published under GPL version 3. See the [`LICENSE`](LICENSE) for details.

