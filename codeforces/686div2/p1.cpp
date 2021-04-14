#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int64_t n,m,r,c;
        cin>>n>>m>>r>>c;
        r--; c--;
        n--,m--;
        int64_t value = max(r+c , max(n-r+c , max(n-r + m-c , r+m-c)));
        cout<<value<<endl;


    }
  return 0;  
}