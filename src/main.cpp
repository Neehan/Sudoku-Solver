#include <bits/stdc++.h>
#include "Board.hpp"
using namespace std;

Board sudoku, b;

uint xrand(uint n){
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<uint>  distr(0, n - 1);
	return distr(generator);
}

void dfs(Board& s){
    if(sudoku.status() == SOLVED) return;
    uint l = s.leastSizeIndex(), c = s.getChoices(l);
    for(uint i = 0; i < 9; i++){
        if((c >> i) % 2 == 0)
        	continue;
        Board test = s;
        test.setChoices(l, 1 << i);
   	    test.solve();
        if(test.status() == SOLVED){
           	sudoku = test;
        }
        else if(test.status() == SOLVABLE){
            dfs(test);
        }
    }
}

int main(){
    cin >> b;
    auto begin = chrono::high_resolution_clock::now();
    dfs(b);
    auto end = chrono::high_resolution_clock::now();
    cout << sudoku;
    double duration = chrono::duration_cast<chrono::microseconds> (end - begin).count() * pow(10, -6);
    cout << "\nExecution time: " << duration << " s" << endl;
}

