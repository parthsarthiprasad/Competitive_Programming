#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
      int n,m;
      cin>>n>>m;
      map<int,int> a,b;
      for(int i=0;i<n;i++){
          int temp;
          cin>>temp;
          a[temp]++;
      }
       for(int i=0;i<m;i++){
          int temp;
          cin>>temp;
          a[temp]++;
      }
      set<int> s;
      for(auto y:a){
          if(y.second>2) continue;
          else {
              s.insert(y.first);
          }
      }
      for(auto y:s){
          cout<<y<<" ";
      }
      cout<<endl;
    //   for(auto y:b){
    //       if(y.second>2) continue;
    //       else {
    //           s.insert(y.first);
    //       }
    //   }

    }
    return 0;
}