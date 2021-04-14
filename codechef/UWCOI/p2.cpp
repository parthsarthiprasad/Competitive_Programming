#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>vec(n), b(m);
        rep(i,0,n)cin>>vec[i];
        rep(i,0,m)cin>>b[i];
        sort(vec.begin(),vec.end());
        sort(b.begin(),b.end());
        int64_t count = 0;
        for(int i=0;i<m;i++){
            count+=(lower_bound(a.begin(),a.end(),b[i]))
        }
        int val = (lower_bound(b.begin(),b.end(),vec[0]) - b.begin());

        cout<<((n*val))<<"\n";
    }
    return 0;
}