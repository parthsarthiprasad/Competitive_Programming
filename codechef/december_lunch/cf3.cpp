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
      vector<int64_t> vec(n);
      rep(i,0,n)cin>>vec[i];
    
      int64_t maxheight = vec[0]+k-1;
      int64_t minheight = max((int64_t)0,vec[0] + 1-k);
      bool possible = true;
      for(int i=1;i<n-1 && possible;i++){
        //   cout<<i<<" "<<maxheight<<" "<<minheight<<" "<<vec[i]<<endl;
        
        
          if(vec[i]+k-1 < minheight || vec[i] > maxheight){

              possible = false;
          }else{
              
              maxheight = vec[i] + k -1+k;
              minheight = max((int64_t)0, vec[i] + 1- k) ;
              
          }
      }
      if(minheight>vec[n-1]+k-1){possible = false;}
      if(possible){
          cout<<"YES\n";
      }else{
          cout<<"NO\n";
      }

    }
    return 0;
}