#include<bits/stdc++.h>
using namespace std;
long int solve(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>vec[i][j];
    }
    map<int,long long int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mp[j-i]+=vec[i][j];
        }
    }
    long long int ans = 0;
    for(auto a:mp){
        ans = max(ans, a.second);
    }
    return ans;
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i= 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;
}