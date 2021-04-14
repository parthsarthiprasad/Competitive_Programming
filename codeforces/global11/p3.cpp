#include<bits/stdc++.h>
using namespace std;
struct stars{
    int x;
    int y;
    long t;
};
bool valid( vector<stars>&st, int i, int j){
    int dist = abs(st[i].x - st[j].x) + abs(st[i].y - st[j].y);
    return (st[i].t - st[j].t >= dist); 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        int r,n , a,b,c;
        cin>>r>>n;
        vector<stars> st(n+1);
        vector<int> dp(n+1,0);
        st[0].x=0;
        st[0].y=0;
        st[0].t=0;
        for(int i=1;i<=n;i++){
            cin>>c>>a>>b;
            a--;b--;
            st[i].x = a;
            st[i].y = b;
            st[i].t = c;
        }
        // sort(st.begin(),st.end(), [&](const stars &a, const stars &b){
        //     return a.t < b.t;
        // });

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(valid(st,i,j)){
                dp[i] = max(dp[i],1 + dp[j]);
                }
            }
        }
        int maxans = 0;
        for(int i=0;i<=n;i++){
            maxans = max(maxans, dp[i]);
        }
        cout<<maxans<<endl;

    }
    return 0;
}