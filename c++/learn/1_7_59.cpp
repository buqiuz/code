#include<bits/stdc++.h>

using namespace std;

//初版模拟，3  2  2  1  1这样填充
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));

        int num=1;
        int x=0;
        for(int i=n;i>0;){
            //右
            for(int j=0;j<i;j++){
                v[x][j+x]=num++;
            }
            //下
            i--;
            for(int j=0;j<i;j++){
                v[j+x+1][n-1-x]=num++;
            }
            //左
            for(int j=i;j>0;j--){
                v[n-1-x][x+j-1]=num++;
            }
            //上
            i--;
            for(int j=i;j>0;j--){
                v[x+j][x]=num++;
            }
            x++;
        }
        return v;
    }
};


// 版本一
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));

        int num=1;
        int x=0;
        for(int i=n-1;i>0;i-=2){
            //右
            for(int j=0;j<i;j++){
                v[x][j+x]=num++;
            }
            //下
            // i--;
            for(int j=0;j<i;j++){
                v[j+x][n-1-x]=num++;
            }
            //左
            for(int j=0;j<i;j++){
                v[n-1-x][n-1-j-x]=num++;
            }
            //上
            // i--;
            for(int j=0;j<i;j++){
                v[n-1-j-x][x]=num++;
            }
            x++;
        }

        if(n%2==1){
            v[n/2][n/2]=num++;
        }
        return v;
    }
};

// 版本二  优化，最优版本
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));

        int num=1;
        int x=0;
        for(int k=n-1;k>0;k-=2){
            int i=x,j=x;    
            //右
            for(;j<n-1-x;j++){
                v[i][j]=num++;
            }
            //下
            for(;i<n-1-x;i++){
                v[i][j]=num++;
            }

            //左
            for(;j>x;j--){
                v[i][j]=num++;
            }
            //上
            for(;i>x;i--){
                v[i][j]=num++;
            }
            x++;
        }

        if(n%2==1){
            v[n/2][n/2]=num++;
        }
        return v;
    }
};

// 版本三
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};