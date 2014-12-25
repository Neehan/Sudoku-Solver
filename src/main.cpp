/**
 * This another simple sudoku solver
 * Uses DFS for searching
 * This code is published under GPL version 3 (or later)
 * copyright Adib Hasan (Neehan)
 **/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

vector< vector<int> > sudoku(81);
vector<int>::iterator myit;

void check(){
    for(int i=0;i<81;i++) if(sudoku[i].size()==1){
        int j=sudoku[i][0], col=i/9, row=i-col*9,tcol=col-col%3,trow=row-row%3;
        for(int k=0;k<9;k++){

            /**ROW CHECK**/

            myit=find(sudoku[col*9+k].begin(),sudoku[col*9+k].end(),j);
            if(myit!=sudoku[col*9+k].end()) sudoku[col*9+k].erase(myit);

            /**COLUMN CHECK**/

            int temp1=sudoku[53][0];
            myit=find(sudoku[k*9+row].begin(),sudoku[k*9+row].end(),j);
            if(myit!=sudoku[k*9+row].end()) sudoku[k*9+row].erase(myit);

            /**SECTOR CHECK**/

            int temp=(tcol+k/3)*9+trow+k%3;
            myit=find(sudoku[temp].begin(),sudoku[temp].end(),j);
            if(myit!=sudoku[temp].end()) sudoku[temp].erase(myit);
        }
        sudoku[i].push_back(j);
    }
}

bool conflict(){
    for(int i=0;i<81;i++) if(sudoku[i].size()==0) return true;
    return false;
}
int FIND_MIN_CHOICE(){
    int MIN=1;
    for(int i=0;i<81;i++)if(sudoku[i].size()>1){
        MIN=i;
        break;
    }
    for(int i=0;i<81;i++)if(sudoku[i].size()>1)MIN=(sudoku[MIN].size()<sudoku[i].size())?MIN:i;
    return MIN;
}
bool solved(){
    for(int i=0;i<81;i++)if(sudoku[i].size()>1) return false;
    return true;
}
void print_sol(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<sudoku[9*i+j].size();k++) cout << sudoku[9*i+j][k];
            for(int k=0;k<3-sudoku[9*i+j].size();k++) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    register int i,j;
    for(i=0;i<9;i++) sudoku[0].push_back(i+1);
    for(i=0,j;i<81;i++)sudoku[i]=sudoku[0];

    cout << "SAMPLE INPUT\n";
    cout << "0 0 0 0 0 0 0 3 9\n";
    cout << "0 0 0 0 0 1 0 0 5\n";
    cout << "0 0 3 0 5 0 8 0 0\n";
    cout << "0 0 8 0 9 0 0 0 6\n";
    cout << "0 7 0 0 0 2 0 0 0\n";
    cout << "1 0 0 4 0 0 0 0 0\n";
    cout << "0 0 9 0 8 0 0 5 0\n";
    cout << "0 2 0 0 0 0 6 0 0\n";
    cout << "4 0 0 7 0 0 0 0 0\nWhere 0 stands for an empty cell\nNow write down your sudoku\n\n";
    for(i=0;i<81;i++){
         cin >> j; ///the cell of ith column and jth row.
         if(j>0){
            sudoku[i].clear();
            sudoku[i].push_back(j);
            check();
         }
    }
    clock_t t=clock();
    stack< vector < vector<int> > > mystack;
    mystack.push(sudoku);
    while(!mystack.empty()){
        sudoku=mystack.top();
        mystack.pop();
        int MIN_CHOICE=FIND_MIN_CHOICE();
        vector <vector <int> > temp=sudoku;
        for(int i=0;i<temp[MIN_CHOICE].size();i++){
            sudoku=temp;
            sudoku[MIN_CHOICE].clear();
            sudoku[MIN_CHOICE].push_back(temp[MIN_CHOICE][i]);
            check();
            if(!conflict()){
                if(solved()){
                    print_sol();
                    t=clock()-t;
                    float a=(float)t/(float)CLOCKS_PER_SEC;
                    cout << "\nRuntime: " << setprecision(3) << a << " Seconds\n";
                    cout << "Press q to quit\n";
                    char quit;
                    cin >> quit;
                    if(quit=='q') return 0;
                }
                else mystack.push(sudoku);
            }
        }
    }
    cout << "Can't solve\n";
}
