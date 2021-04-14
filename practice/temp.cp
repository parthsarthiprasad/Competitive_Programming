#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //since n<100, generate all pairs
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    set<pair<int,int>> ans;
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mp[{vec[i], vec[j]}]++;
            if(mp[{vec[i],vec[j]}] ==1 && mp[{vec[i],vec[j]}]<)
        }
    }
    for(int i=0;i<n-1;i++){
        int j = i+1;
         mp[{vec[i], vec[j]}]++;
            if(mp[{vec[i],vec[j]}] ==2){
                ans.insert({vec[i],vec[j]});
            }
    }
    for(auto a:ans){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;    
}