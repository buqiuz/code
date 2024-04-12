#include<iostream>
#include<vector>

using namespace std;
struct BitNode{
    int data;
    BitNode *tree_left=nullptr;
    BitNode *tree_right=nullptr;
};
bool m[10];
void creat (BitNode* &tree,vector<int> &v_back,vector<int> &v_mid,int& j){
    if (j>=0)
    {
        for(int i=0;i<v_mid.size();i++){
        if(v_mid[i]==v_back[j]){
            
                tree=new BitNode;
                tree->data=v_back[j--];
                m[i]=0;

            if(i<v_mid.size()-1&&m[i+1]!=0){

                creat(tree->tree_right,v_back,v_mid,j);

            } if(i>0&&m[i-1]!=0){

                creat(tree->tree_left,v_back,v_mid,j);
            }
        }
    }
    }

}
void pre(BitNode* &tree) {
    if (tree != nullptr) {
        
        cout << " "<<tree->data ;
        pre(tree->tree_left);
        pre(tree->tree_right);
    }
}
int max(int a,int b    ){
    if(a>b)return a;
    return b;
}
int depth(BitNode* tree){
    if(tree==nullptr){
        return 0;
    }else{
        return 1+max(depth(tree->tree_left),depth(tree->tree_right));
    }
}
int main(){
    int n;
    while (cin>>n)
    {
for(int i=0;i<10;i++){
    m[i]=1;
}
    BitNode *tree;
    vector<int> v_back(n),v_mid(n);
    for(int i=0;i<n;i++){
        cin>>v_back[i];
    }

    for(int i=0;i<n;i++){
        cin>>v_mid[i];
    }
    int a=v_mid[n-1];
    int j=n-1;
    creat(tree,v_back,v_mid,j);
    
    cout<<depth(tree);
    pre(tree);
        cout<<endl;
    }
    
    return 0;
}