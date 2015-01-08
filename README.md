Sudoku-Solver
=============

This is another simple sudoku solver. Have fun!

##How to install
[Download the latest](http://www.github.com/Neehan/Sudoku-Solver/releases) Sudoku-Solver and unzip it. Run `Sudoku-Solver` (for ubuntu) or `Sudoku-Solver.exe` (for windows). That's it.

##How to use

###Method 1

Write the value of each cell separated by a space. Value of an empty cell is either `0` or `.` . However, you may make a typo while typing the sudoku. That's why I recommend the alternative method.

###Method 2

Open sudoku.txt. You will see two blank sudokus there. One with empty cells as ., and the other with 0. Choose whichever you prefer and substitute the cells with clues from your sudoku. Now copy the sudoku and close the file without saving. After that run the Sudoku-Solver, paste the sudoku and then press enter.

##Example

Let's solve the following sudoku.
```
+---+---+---+---+---+---+---+---+---+
| 1 |   |   | 9 | 2 |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
| 5 | 2 | 4 |   | 1 |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   | 7 |   |
+---+---+---+---+---+---+---+---+---+
|   | 5 |   |   |   | 8 | 1 |   | 2 |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
| 4 |   | 2 | 7 |   |   |   | 9 |   |
+---+---+---+---+---+---+---+---+---+
|   | 6 |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   | 3 |   | 9 | 4 | 5 |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   | 7 | 1 |   |   | 6 |
+---+---+---+---+---+---+---+---+---+
```
Following method 1, the input will be,

```
1 0 0 9 2 0 0 0 0
5 2 4 0 1 0 0 0 0
0 0 0 0 0 0 0 7 0
0 5 0 0 0 8 1 0 2
0 0 0 0 0 0 0 0 0
4 0 2 7 0 0 0 9 0
0 6 0 0 0 0 0 0 0
0 0 0 0 3 0 9 4 5
0 0 0 0 7 1 0 0 6
```
Or,
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
If you follow method 2, the input will be,
```
1 0 0 | 9 2 0 | 0 0 0
5 2 4 | 0 1 0 | 0 0 0
0 0 0 | 0 0 0 | 0 7 0
------+-------+------
0 5 0 | 0 0 8 | 1 0 2
0 0 0 | 0 0 0 | 0 0 0
4 0 2 | 7 0 0 | 0 9 0
------+-------+------
0 6 0 | 0 0 0 | 0 0 0
0 0 0 | 0 3 0 | 9 4 5
0 0 0 | 0 7 1 | 0 0 6
```
Or,
```
1 . . | 9 2 . | . . .
5 2 4 | . 1 . | . . .
. . . | . . . | . 7 .
------+-------+------
. 5 . | . . 8 | 1 . .
. . . | . . . | . . .
4 . 2 | 7 . . | . 9 .
------+-------+------
. 6 . | . . . | . . .
. . . | . 3 . | 9 4 5
. . . | . 7 1 | . . 6
```
**Note: The given sudoku must have at least one solution.**
##Sample Output
```
+-------+-------+-------+
| 7 5 1 | 8 4 6 | 2 3 9 |
| 8 9 2 | 3 7 1 | 4 6 5 |
| 6 4 3 | 2 5 9 | 8 7 1 |
+-------+-------+-------+
| 2 3 8 | 1 9 7 | 5 4 6 |
| 9 7 4 | 5 6 2 | 3 1 8 |
| 1 6 5 | 4 3 8 | 9 2 7 |
+-------+-------+-------+
| 3 1 9 | 6 8 4 | 7 5 2 |
| 5 2 7 | 9 1 3 | 6 8 4 |
| 4 8 6 | 7 2 5 | 1 9 3 |
+-------+-------+-------+

Runtime: 0.026 Seconds
Press q to quit
```
##License
This is  published under GPL version 3. See the `LICENSE` for details.

