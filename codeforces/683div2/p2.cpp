#include<bits/stdc++.h>
using namespace std;
#define rep(p,a,b) for(int p=a;p<b;p++)
#define ll int64_t

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n, vector<int> (m));
        rep(i,0,n)rep(j,0,m){cin>>vec[i][j];}
        int minval = abs(vec[0][0]);
        long long int sum = 0;
        int countive = 0;
        bool iszero= false;
        rep(i,0,n) rep(j,0,m){
            minval = min(minval, abs(vec[i][j]));
            sum+=abs(vec[i][j]);
            if(vec[i][j]<0)countive++;
            else if(vec[i][j]==0) iszero = true;
        }
        if(iszero || countive%2==0) cout<<sum<<endl;
        else if(countive&1) cout<<sum - 2*minval<<endl;

    }
    return 0;
    
}