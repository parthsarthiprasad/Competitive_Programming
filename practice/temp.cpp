#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insertnode(node *root, string temp, int dat){
    node * trav = root;
    for(auto a:temp){
        if(a=='L'){
            if(trav->left==NULL){
                trav->left = new node(dat);
                trav= trav->left;
            }else{
            trav= trav->left;
            }
        }else{
            if(trav->right==NULL){
                trav->right = new node(dat);
                trav= trav->right;
            }else{
            trav= trav->right;
            }
        } 
    }
    return ;
}

int BalancedNode(int N, int Root, string pos[], int val[]){
     struct node* root = new node(Root);
     map<string,int> mp;
     for(int i=0;i<N;i++){
         mp.insert({pos[i], val[i]});
     }
     for(auto a:mp){
        insertnode(root, a.first,a.second);
     }

}