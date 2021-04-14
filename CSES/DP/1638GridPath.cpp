#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n;
//forgot to memoize it in first attempty
// int findcol(char ptr[1000][1000],int i,int j ){
//     if(i==0 && j==0) return 1;
//     else if(i<0 || j<0) return 0;
//     if(ptr[i][j]=='*') return 0;
//     return (findcol(ptr,i,j-1) + findcol(ptr,i-1,j))%mod;
// }
int findcol(char ptr[1000][1000]){
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    // for(auto a:dp){
    //    for(int i=0;i<n;i++)cout<<*(a+i)<<" "; cout<<endl;
    // }
    for(int i=0;i<n;i++){
        if(ptr[i][0]=='*') break;
        dp[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        if(ptr[0][i]=='*') break;
        dp[0][i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(ptr[i][j]=='*'){
                dp[i][j]=0;
            } 
            else{
                dp[i][j] = (dp[i-1][j]+ dp[i][j-1])%mod;
            }
        }
    }
    return dp[n-1][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    char ptr[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>ptr[i][j];
    }
    //cout<<findcol(ptr,n-1,n-1)<<"\n";
    cout<<findcol(ptr)<<"\n";
    return 0;
}

/*
4
....
.*..
...*
*...
*/