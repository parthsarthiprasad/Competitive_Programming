//subset sum problem
#include<bits/stdc++.h>
using namespace std;
void printsubsetrecursive(vector<vector<bool>> &subset, int n,int k, int ptr[], vector<int> &path){
    if(n==0 && k!=0 &&subset[0][k]){
        path.push_back(ptr[0]);
        for(auto a:path){
            cout<<a<<" ";
        }
        cout<<endl;
        return ;
    }
    if(n==0 && k==0){
        for(auto a:path){
            cout<<a<<" ";
        }
        cout<<endl;
        return;
    }
    if(subset[n-1][k]){
        printsubsetrecursive(subset,n-1,k,ptr,path);
    }
    if(ptr[n-1]<=k && subset[n-1][k-ptr[n-1]]){
        path.push_back(ptr[n-1]);
        printsubsetrecursive(subset,n-1,k-ptr[n-1],ptr,path);
        path.pop_back();
    }

  
    return ;
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    vector<vector<bool>> subset(n+1,vector<bool>(k+1,false));
    for(int i=0;i<=k;i++) subset[0][k] = false;
    for(int i=0;i<=n;i++) subset[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(ptr[i-1]<=j){
                subset[i][j] = subset[i-1][j]||subset[i-1][j-ptr[i-1]];
            }else{
                subset[i][j] = subset[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++) cout<<subset[i][j]<<" ";
        cout<<endl;
    }
    vector<int> path;
    printsubsetrecursive(subset,n,k, ptr,path);

}