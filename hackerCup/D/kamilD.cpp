#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF =(ll) 1e9+5; 
ll findrecur(ll ptr[], ll dp[], int index, int pass, int n){
    if(index<0) return INF;
    if(index==0) return 0;
    if(dp[index]!=INF) return dp[index];
    else{
        ll val= INF;
        for(int i=1;i<=pass && index-i>=0;i++){
            val = min(val, ptr[index-i] + findrecur(ptr,dp,index-i, pass,n));
        }
        return dp[index] = val;
    }
}
ll solve(){
    int n,m;
    scanf("%d%d", &n, &m);
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        scanf("%d", &cost[i]);
        if(cost[i] == 0) cost[i] = INF;
    }
    int B = 1;
    while(B<n){
        B*=2;
    }
    vector<int> tree(2*B);
    for(int i=0;i<n;++i){
        tree[B+i] = cost[i];
    }
    for(int i=B-1; i>=1; --i){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    long long answer =0;
    for(int i = m;i<n;++i){
        int L = B +i -m;
        int R = B +i;
        int small = min(tree[L], tree[R]);
        while(L+1<R){
            small = min(small, tree[L+1]);
            small = min(small, tree[R-1]);
            L/=2;
            R/=2;
        }
        answer+=small;

    }
    printf("%lld\n", answer);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        printf("Case #%d: %lld\n",i++,solve());
    }
    return 0;
}