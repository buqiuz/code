#include<iostream>
#include<vector>

using namespace std;

struct subArray{
    int start=0,end=-1;
};
subArray findMaxSubarray(vector<int> v){
    subArray node;
    int current_sum=0;
    int max_sum=-1;
    for(int i=0;i<v.size();i++){
        current_sum+=v[i];
        if(current_sum>max_sum){
            max_sum=current_sum;
            node.end=i;
        }
        if(current_sum<0){
            current_sum=0;
            node.start=i+1;
        }
    }
    return node;
    
}
int main(){
    vector<int> v{-2, 11, -4, 13, -5, -2,8};
    subArray z=findMaxSubarray(v);
    cout<<z.start<<" "<<z.end;
    return 0;
}