#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
const int nax = 2e5+1;
#define ll long long 
using namespace std;
ll solve(){
    int n,m;
    cin>>n>>m;
    string mat[n];
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<mat[i][j]; cout<<endl;
    // }
    // cout<<endl;
    int count = 0;
    for(int i=0;i<n-1;i++){
        if(mat[i][m-1]=='R') count++;
    }
    for(int i=0;i<m-1;i++){
        if(mat[n-1][i]=='D') count++;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}