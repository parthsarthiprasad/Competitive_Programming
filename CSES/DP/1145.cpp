#include<bits/stdc++.h>
using namespace std;

struct comp{
    bool operator() (const pair<int,int> &a, const pair<int,int> &b){
    if(a.first != b.first) return a.first>b.first;
    else return a.second>b.second;
}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n), dp(n,1);
    for(int i=0;i<n;i++)cin>>vec[i];

    set<pair<int,int>, comp> st;
    st.insert({vec[i],0});
    for(int i=1;i<n;i++){
        auto it = lower_bound(st.begin(),st.end(), vec[i]);
        if(it!=st.end()){
            dp[i] = dp[it->second]+1;
        }
        
        st.insert({vec[i],i});
    }
    cout<<*max_element(dp.begin(),dp.end());
}