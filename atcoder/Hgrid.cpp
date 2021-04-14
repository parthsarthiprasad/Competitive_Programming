//this is simple traversal can be done in bottom up manner as well
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int mod = 1e9+7;
    int n,m;
    cin>>n>>m;
    char ptr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a; cin>>a;
            ptr[i][j] = a;
        }
    }

    ll ans[n][m];
    ans[0][0]=1;
    for(int i=1;i<n;i++){
        ans[i][0]=ans[i-1][0];
        if(ptr[i][0]=='#'){
            ans[i][0]=0;
        }
    }
    for(int j=1;j<m;j++){
         ans[0][j]=ans[0][j-1];
        if(ptr[0][j]=='#'){
            ans[0][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(ptr[i][j]=='#'){
                ans[i][j]=0;
            }else{
                (ans[i][j]=ans[i-1][j]+ ans[i][j-1])%=mod;
            }
        }
    }
    cout<<ans[n-1][m-1]<<endl;
    return 0;
}