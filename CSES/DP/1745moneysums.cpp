#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(), vec.end());
    set<int> dp;
    dp.insert(vec[0]);
    for(int i=1;i<n;i++){
        int temp = dp.size();
        set<int> ans;
        ans.insert(vec[i]);
        for(auto a:dp){
            ans.insert(a+vec[i]);
        }
        for(auto a:ans){
            dp.insert(a);
        }
    }
    cout<<dp.size()<<endl;
    for(auto a:dp) cout<<a<<" ";
    cout<<endl;

}