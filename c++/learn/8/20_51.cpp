#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
private:
    vector<vector<string>> ret;
    bool isValid(vector<string>& path,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(path[i][col]=='Q') return false;
        }
        //检查左上方
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(path[i][j]=='Q') return false;
        }
        //检查右上方
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(path[i][j]=='Q') return false;
        }
        return true;
    }
    void backTrack(int& n,vector<string>& path,int row){
        if(row==n){
            ret.push_back(path);
            return ;
        }

        for(int col=0;col<n;col++){
            if(isValid(path,row,col,n)){
                string s(n,'.');
                s[col]='Q';
                path.push_back(s);
                backTrack(n,path,row+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path;
        backTrack(n,path,0);
        return ret;
    }
};


//精简
class Solution {
private:
    vector<vector<string>> ret;
    bool isValid(vector<string>& path,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(path[i][col]=='Q') return false;
        }
        //检查左上方
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(path[i][j]=='Q') return false;
        }
        //检查右上方
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(path[i][j]=='Q') return false;
        }
        return true;
    }
    void backTrack(int& n,vector<string>& path,int row){
        if(row==n){
            ret.push_back(path);
            return ;
        }

        for(int col=0;col<n;col++){
            if(isValid(path,row,col,n)){
                path[row][col]='Q';
                backTrack(n,path,row+1);
                path[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n,string(n,'.'));
        backTrack(n,path,0);
        return ret;
    }
};