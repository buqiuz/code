#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    std::vector<int> v,ret_total;
    int total=0;
    
    int cal_total(int low,int high){
        return ret_total[high]-ret_total[low]+v[low];
    }
    
    Solution(vector<int> v):v(v){
        for (int i = 0; i < v.size(); i++) {
            total+=v[i];
            ret_total.emplace_back(total);
        }
    };
};

int main(){
    int n;
    // cin>>n;
    scanf("%d",&n);
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        // cin>>v[i];
        scanf("%d",&v[i]);
    }
    
    int low,high;
    Solution s(v);
    
    while(~scanf("%d%d",&low,&high)){
        // cout<<s.cal_total(low,high)<<endl;
        printf("%d\n",s.cal_total(low,high));
    }
}

//版本一
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n, a, b;
//     cin >> n;
//     vector<int> vec(n);
//     vector<int> p(n);
//     int presum = 0;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &vec[i]);
//         presum += vec[i];
//         p[i] = presum;
//     }

//     while (~scanf("%d%d", &a, &b)) {
//         int sum;
//         if (a == 0) sum = p[b];
//         else sum = p[b] - p[a - 1];
//         printf("%d\n", sum);
//     }
// }

