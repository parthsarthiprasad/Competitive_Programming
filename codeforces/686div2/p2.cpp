#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        int64_t count = 1e17;
        rep(i,1,101){
            int64_t tcount = 0;
            rep(j,0,n){
                if(vec[j]!=i){
                    tcount++;
                    j+=(k-1);
                }
            }
            count = min(count, tcount);
        }
        cout<<count<<endl;

 
    }
  return 0;  
}