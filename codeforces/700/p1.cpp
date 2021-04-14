#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> vec(n);
      for(int i=0;i<n;i++)cin>>vec[i];
      int count = 0;
      for(int i=0;i<n-1;i++){
          int val = max(vec[i] - i,(int64_t)0);
          vec[i+1]+=val;
          vec[i] = min(i,vec[i]);
      }
      bool possible = true;
      for(int i=1;i<n;i++){
          if(vec[i]<=vec[i-1]){
              possible = false;
          }
      }
      if(possible){
          cout<<"YES\n";
      }else{
          cout<<"NO\n";
      }
    }
    


}