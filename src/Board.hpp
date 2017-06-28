#ifndef BOARD_HPP
#define BOARD_HPP
#define SOLVED       2
#define SOLVABLE     1
#define UNSOLVABLE   0
#include <bits/stdc++.h>

class Board{
public:
    Board();
    Board(std::string sudoku);
    void setChoices(uint i, uint val);
    uint getChoices(uint i);
    uint valueAt(uint i);
    void solve();
    uint status();
    uint leastSizeIndex();
    uint getSize(uint i);
    friend std::istream& operator>>(std::istream& input, Board& b);
    friend std::ostream& operator<<(std::ostream& output, Board& b);
private:
    uint cell[81];
    static uint size[512];
    void addChoice(uint i, uint n);
    void discardChoice(uint i, uint n);
};
#endif
