#include<bits/stdc++.h>
using namespace std;
int64_t findanswer(vector<vector<int64_t>> &dp,int bm, vector<int> & prices, 
                   vector<string> &vitamins, int costsofar, 
                   int index, int msize){
    if(dp[bm][index]!=INT_MAX) return dp[bm][index];
    if(bm == 7) return costsofar;
    if(index == msize ) return INT_MAX;
    int64_t &mincost = dp[bm][index];

    mincost = findanswer(dp,bm, prices, vitamins, costsofar, index+1, msize);
    dp[bm][index] = mincost;
    for(auto a: vitamins[index]){
        bm = bm | (1<<((a - 'A')));
    }
    mincost = min(mincost, findanswer(dp,bm, prices, vitamins, costsofar + prices[index], index+1, msize) );
    return mincost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> prices(n);
    vector<string> vitamins(n);
    vector<vector<int64_t>> dp(8,vector<int64_t>(n, INT_MAX));
    for(int i=0;i<n;i++){
        cin>>prices[i];
        cin>>vitamins[i];
        sort(vitamins[i].begin(), vitamins[i].end());
    }
    int answer = 0;
    int64_t mincost = findanswer(dp,answer, prices,vitamins, 0,0,n);
    if(mincost==INT_MAX) mincost = -1;
    cout<<mincost<<endl;
    cout<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}