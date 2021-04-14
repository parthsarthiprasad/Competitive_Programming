#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      vector<int> vec(n);
      rep(i,0,n)cin>>vec[i];
        int count = 0;
      int sum = 0;
      
      for(int i=0;i<n;i++){
         sum+=vec[i];
      }
      if(sum%k!=0)count++;
      cout<<count<<endl;
    }
    return 0;
}