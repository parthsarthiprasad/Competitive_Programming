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
      for(int i=0;i<n;i++)cin>>vec[i];
      sort(vec.begin(),vec.end());
      map<int,int> mp;
      for(auto a:vec){
          mp[a]++;
      }
      vector<int> values;
      for(auto a:mp){
          values.push_back(a.second);
      }
      sort(values.begin(),values.end());
      vector<int64_t> prefixjump(values.size()+1,0);
      vector<int64_t> suffixjump(values.size()+1,0);
      for(int i=1;i<values.size();i++){
          suffixjump[i] = suffixjump[i-1] + (i*(values[i]-values[i-1]));
      }
      for(int i=values.size()-2;i>=0;i--){
          prefixjump[i] = prefixjump[i+1] + (values.size()-i-1)*(values[i+1] - values[i]);
      }
      int64_t ans = 1e18;
      for(int i=0;i<values.size();i++){
        //   cout<<prefixjump[i]<<" "<<suffixjump[i]<<endl;
            if(values[i]&1){
                if(i>0 ){
                    int64_t tempval = prefixjump[i-1] + (values[i]  - values[i-1] -1)*(i)  + suffixjump[i]+ (values.size()-i);
                    ans = min(ans,tempval);
                }
                if(i<values.size()-1){
                    int64_t tempval = prefixjump[i] + (i+1) + suffixjump[i+1] + (values.size()-i-1)*(values[i+1] - values[i] -1);
                    ans = min(ans,tempval);
                }
            }else{
                ans = min(ans, prefixjump[i] + suffixjump[i]);
            }   
      }
      cout<<ans<<endl;

    }
    return 0;
}