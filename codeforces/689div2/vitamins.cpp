#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int search( int mask, vector<vector<int>> & dp,
            vector<int>& price, vector<string> & vitamins, int index, int n){
    if(mask==7) return 0;
    if(index == n ) return INF;
    if(dp[index][mask]!=INF) return dp[index][mask];
    int newmask = mask;
    for(auto a:vitamins[index]){
        newmask = newmask | (1<<(a-'A'));
    }
    // cout<<mask<<" "<<newmask<<" "<<index<<endl;
    if(newmask!=mask) dp[index][mask] = min(dp[index][mask], index>0?dp[index-1][mask]:0 + price[index] + search( newmask, dp, price, vitamins,index+1,n));
    return dp[index][mask];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> price(n);
    vector<string> vitamins(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
        cin>>vitamins[i];
        sort(vitamins[i].begin(), vitamins[i].end());
    }

    vector<vector<int>> dp(n,vector<int>(8,INF));
    int mask = 0;
    
   cout<< search(mask, dp, price, vitamins, 0 ,n);
//    for(int i=0;i<n;i++){
//         for(int j=0;j<8;j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }

}