#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> vec(n);
      rep(i,0,n)cin>>vec[i];
      int m;
      cin>>m;
      vector<int> bc(m);
      rep(i,0,m)cin>>bc[i];
   
      int sum = 0;
      vector<int> prefixa(n+1,0);
      vector<int> prefixb(m+1,0);
      for(int i=0;i<n;i++){
          prefixa[i+1] = prefixa[i] + vec[i];
      }
      for(int i=0;i<m;i++){
          prefixb[i+1] = prefixb[i] + bc[i];
      }
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
              sum = max(sum, prefixa[i] + prefixb[j]);
          }
      }
      cout<<sum<<endl;
    }
    return 0;
}