#include<bits/stdc++.h>
using namespace std;


long findans(vector<vector<int>> &dp, vector<long> &prefixsum, vector<int> &stones, int start, int end , int n){
    if(dp[start][end]!=-1) return dp[start][end];
    int &ans = dp[start][end];
    if(start==end){
        return ans=0;
    }
    if(start+1==end){
        return ans=min(stones[start], stones[end]);
    }

    long minval = start==0?0:prefixsum[start-1];
    long maxval = prefixsum[end];
    for(int i=start;i<end;i++){
        long left = prefixsum[i] - minval;
        long right = maxval - prefixsum[i];
        //cout<<left<<" "<<right<<" "<<start<<" "<<end<<endl;
        if(left>right){
            ans = max((long)ans, right + findans(dp,prefixsum, stones,i+1, end, n));
        }else if(left<right){
            ans = max((long)ans, left+ findans(dp,prefixsum, stones, start,i,n));
        }else{
            ans = max({(long)ans, 
                        right + findans(dp,prefixsum, stones,i+1, end, n),
                        left+ findans(dp,prefixsum, stones, start,i,n)});
        }
        
    }
    return ans;

    
}
int stonegame(vector<int>& stoneValue) {
    
    int n = stoneValue.size();
    vector<long> prefixsum(n) ;
    vector<vector<int>> dp(n, vector<int>(n,-1));
    prefixsum[0] = stoneValue[0];
    for(int i=1;i<n;i++){
        prefixsum[i]=prefixsum[i-1] + stoneValue[i];
    }
    long ans = findans(dp,prefixsum, stoneValue, 0,n-1, n);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> ptr(n);
    for(int i=0;i<n;++i) cin>>ptr[i];
    cout<<stonegame(ptr);
}