#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board,int row,int col,char k){
        //行
        for(int i=0;i<9;i++) if(board[row][i]==k) return false;
        //列
        for(int i=0;i<9;i++) if(board[i][col]==k) return false;
        //9宫格
        for(int i=row/3*3;i<row/3*3+3;i++){
            for(int j=col/3*3;j<col/3*3+3;j++){
                if(board[i][j]==k) return false;
            }
        }
        return true;
    }
    bool backTracking(vector<vector<char>>& board){   //找到一个就返回
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j]=k;
                            if(backTracking(board)) return true; 
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board);
    }
};