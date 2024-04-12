#include<iostream>
#include<vector>

using namespace std;

int find_min (vector<int> v){
    int min=v[0];
    for (int i = v.size()%2; i < v.size(); i+=2)   //若是奇数个，则从v[1]开始，否则从v[0]开始
    {
        if(v[i]<v[i+1]){
            if(v[i]<min){
                min=v[i];
            }
        }else{
            if(v[i+1]<min){
                min=v[i+1];
            }
        }
    } 
    return min;    
}

int main(){
    vector<int> v{1,5,7,3,8,9,-5,2,8,6,-2,98};
    cout<<find_min(v);

    return 0;
}
