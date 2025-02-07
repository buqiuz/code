#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> ret;
    string path;
    void backTracing (string& s,int startIndex,int depth){
        if(depth>4) return ;  //剪枝    
        if(startIndex>=s.size()&&depth==4){
            ret.push_back(path);
            return ;
        }

        for(int i=startIndex;i<s.size()&&i-startIndex<=2;i++){
            string temp = s.substr(startIndex,i-startIndex+1);
            if((temp.size() == 3&&temp>"255")||(i>startIndex&&s[startIndex]=='0')) break;  //判断前导零和ip<=255
            int oldSize = path.size();
            path+=oldSize==0?temp:"."+temp;
            backTracing(s,i+1,depth+1);
            path.resize(oldSize);    //删除时直接重新分配内存，优化
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backTracing(s,0,0);
        return ret;
    }
};