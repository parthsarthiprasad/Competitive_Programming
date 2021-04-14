//lowerst common subsequence
#include<bits/stdc++.h>
using namespace std;

// findlcs resursive
int findlcs(string &a, string &b, int z, int x){
    if(z==0 || x==0) return 0;
    if(a[z-1]==b[x-1]) return 1+findlcs(a,b,z-1,x-1);
    else return max(findlcs(a,b,z-1,x), findlcs(a,b,z,x-1));
}
// findlcs memosisatio
int findlcsmemoUtil(string &a, string &b, int z, int x, int **ptr){
    if(z==0 || x==0) return 0;
    if(dp[z][x]!=0){
        return dp[z][x];
    }else {
        if(a[z-1]==b[x-1]) {
            int val = findlcsmemoUtil(a,b,z-1,x-1,ptr);
            dp[z][x]=val+1;
            return dp[z][x];
        }else{
            int val1 = findlcsmemoUtil(a,b,z-1,x,ptr);
            int val2= findlcsmemoUtil(a,b,z,x-1,ptr);
            dp[z][x] = max(val1,val2);
            return dp[z][x];
        }
        
    }
       
}

//findlcs tabulation
int findclstab(string &a, string &b, int z,int x){
    int dp[z+1][x+1];
    memset(dp,0,sizeof(dp));
    int i,j;

    //bottom up approach where
    //dp[i][j] is sting from 0...i and 0..j
    //dp[0][x], dp[x][0] is phi
    for(int i=1;i<=z;i++){
        for(int j=1;j<=x;j++){
            if(a[i]==b[j]){
                dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[z][x];
}
int findlcsmemo(string &a, string &b, int z,int x){
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    findlcsmemoUtil(a,b,z,x,dp);
}
void solve(){
    string a,b;
    cin>>a>>b;
    cout<<findlcs(a,b,sizeof(a), sizeof(b));
}
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     while(t--){
         solve();
     }
     return 0;
 }