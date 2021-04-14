#include<bits/stdc++.h>
using namespace std;
void input(vector<int> &p, int a){
    for(int i=0;i<a;i++) cin>>p[i];
}
void display(vector<int> &a){
    cout<<endl;
    for(auto x:a) cout<<x<<" "; cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,g,b;
    cin>>r>>g>>b;
    int dp[r+1][g+1][b+1];
    for(int i=0;i<=r;i++) dp[i][0][0] = 0;
    for(int j=0;j<=g;j++) dp[0][j][0] = 0;
    for(int k=0;k<=b;k++) dp[0][0][k] = 0;
    vector<int> l(r), m(g), n(b);
    input(l,r);
    input(m,g);
    input(n,b);
    sort(l.begin(), l.end());
    sort(m.begin(), m.end());
    sort(n.begin(), n.end());
    // display(l);
    // display(m);
    // display(n);
     for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
            for(int k=0;k<=b;k++){
                 dp[i][j][k] = 0;
            }
        }
    }
    for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
            for(int k=0;k<= b;k++){
                // dp[i][j][k] = max(dp[i][j-1][k-1] + m[j-1]*n[k-1],
                //               max(dp[i-1][j-1][k] + l[i-1]*m[j-1],
                //               max(dp[i][j][k],
                //                   dp[i-1][j][k-1] + l[i-1]*n[k-1]))); 

                if(i&&j){
                    dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j-1][k] + l[i-1]*m[j-1]); 
                }
                if(i&&k){
                    dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j][k-1] + l[i-1]*n[k-1]); 
                }
                if(k&&j){
                    dp[i][j][k] = max(dp[i][j][k] , dp[i][j-1][k-1] + n[k-1]*m[j-1]); 
                }                                                                
            }
        }
    }

    cout<<dp[r][g][b]<<endl;
    // int ans = 0;
    // for(int i=0;i<=r;i++){
    //     for(int j=0;j<=g;j++){
    //         for(int k=0;k<=b;k++){
    //             ans= max(ans, dp[i][j][k]);
    //         }
    //     }
    // }
    // cout<<ans<<endl;
    return 0;
}