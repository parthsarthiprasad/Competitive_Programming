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
       vector<int> ans = {1,7,0,4,2,6,5,3};
       if(k<=8){
           for(int i=0;i<k;i++){
               cout<<ans[i]<<" "<<ans[(i+1)%8]<<endl;
           }
       }
    }
    return 0;
}