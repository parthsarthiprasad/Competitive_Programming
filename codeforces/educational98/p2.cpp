#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int64_t maxdiff = 0;
        vector<int64_t> vec(n);
        rep(i,0,n)cin>>vec[i];
        sort(vec.begin(), vec.end());
        rep(i,0,n){
            int64_t tdiff = 0;
            int64_t lg = -1;
            rep(j,0,n){
                if(j==i) continue;
                lg = max(lg, vec[j]);
            }
            rep(j,0,n){
                if(i==j) continue;
                tdiff+= (lg - vec[j]);
            }
            if(tdiff<vec[i]){
                tdiff = ((vec[i]+n-1)/(n-1))*(n+1);
            }
            maxdiff = max(maxdiff, tdiff- vec[i]);
        }
        cout<<maxdiff<<endl;
        
        
    }
    return 0;
}