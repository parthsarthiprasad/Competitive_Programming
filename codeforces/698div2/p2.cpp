#include<bits/stdc++.h>
using namespace std;
map<int,int>::iterator findlb(map<int,int> &s, int val){
    auto temp = s.lower_bound(val);
    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;
    //    reverse(s.begin(),s.end());
        map<int,int> mp;
        vector<int> vec(s.size()+1,1e8);
       vec[0] = 0;
    //    s.insert({vec[0],0});
    //    mp[vec[0]] = 0;
       for(int i=0;i<n;i++){
           auto it = findlb(mp,vec[i]);
           if(it->first<=vec[i]){
                vec[i] = vec[it->second] + (i-it->second-1);
           }else{
               vec[i] = i;
           }
           mp[vec[i]] = i;
       }

       int res = n;
       for(int i=0;i<n;i++){
           res = min(res, vec[i] + (n-i-1));
       }
       cout<<res<<endl;

       
    }
    return 0;
}