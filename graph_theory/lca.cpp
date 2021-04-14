//LCA of nodes
// slow pre query O(N) , fast per query O(logn)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right =NULL;
    }

};
bool findpath(Node *root, vector<int> &path, int k){
    if (root==NULL) return false;
    path.pb(root->data);
    if(root->data == k) return true;
    if((root->left && findpath(root->left, path,k)) ||
        (root->right && findpath(root->right, path, k))) return true;
    path.pop_back();
    return false;
}
Node * newNode(int k){
    Node * temp = new Node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}
int lca(Node *root, int n1, int n2){
    vector<int> path1, path2;
    if(!findpath(root,path1, n1) || !findpath(root,path2,n2)) return -1;
    int i;
    for(i=0;i<path1.size() && i<path2.size() ; i++ )
        if(path1[i] != path2[i]) break;
    return path1[i-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout<<lca(root,4,5)<<"\n";
    cout<<lca(root,4,6)<<"\n";
    cout<<lca(root,3,4)<<"\n";
    return 0;
}