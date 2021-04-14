#include<bits/stdc++.h>
using namespace std;
struct node{
    bool bit;
    int d;
    node *left;
    node* right;
};

void insertnode(node*root , int data){
    long long int i=1;
    node * temp = root;
    node * prev = NULL;
    bool dir=false;
    while(i<=data && !(root->left==NULL && root->right==NULL)){
        if(root->bit&i){
            if(root->right==NULL){
                dir = true;
                break;
            }
            prev=root;
            root=root->right;
            i*=2;
        }
        else{
            if(root->left==NULL){
                dir==false;
                break;
            }
            prev=root;
            root=root->left;
        }
    }
    while(i<=data){
        node * t = new node;
        t->bit = (data&i);
        t->left==NULL;
        t->right==NULL;
        if(t->bit){
            root->right=t;
            root=root->right;
        }else{
            root->left=t;
            root=root->left;
        }
        i*=2;
    }
    root=temp;
    return ;
    
}

// int findnode(node * root, int val){

// }

void display(node * root){
    if(root==NULL) return;
    cout<<root->bit<<" ";
    display(root->left);
    display(root->right);
}
int solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    node * root = new node;
    root->bit=0;
    root->left = NULL;
    root->right=NULL;
    for(int i=0;i<n;i++){
        insertnode(root,a[i]);
    }

    display(root);
    return 0;

}
//create a binary tree like structure

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve()<<endl;
}