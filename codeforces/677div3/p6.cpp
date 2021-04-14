#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) or(int i=0;i<int(n);++i)
const int N = 70;
const int INF = 1e9;
int a[N][N];
int dp[N][N][N][N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    forn(i,n) forn(j,m){
        cin>>a[i][j];
    }
    forn(i,N)for(j,N)forn(cnt,N)forn(rem,N) dp[i][j][cnt][rem] = -INF;
    dp[0][0][0][0] = 0;
    forn(i,N)for(j,N)forn(cnt,m/2 +1)forn(rem,N) {
        dp[i][j][cnt][rem] = -INF;
    }

}