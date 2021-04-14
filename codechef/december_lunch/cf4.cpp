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
      cout<<n-1<<endl;
      cout<<n<<" "<<n-1<<endl;
      for(int i=1;i<n-1;i++){
          cout<<i<<" "<<i+1<<endl;
      }
    }
    return 0;
}