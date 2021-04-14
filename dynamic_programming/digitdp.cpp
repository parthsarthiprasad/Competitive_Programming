#include<bits/stdc++.h>
using namespace std;
string l,r;
const int N = 0;
int dp[20][2];

int calc(int pos, int small, sint &r){
    if(pos == r.size() ) return 1;
    int &ans = dp[pos][small];
    if(ans !=-1) return ans;
    ans = 0;
    if(pos%2 == 0){
        for(int i=1; i< 10;i+=2){
            if(small || (i< r[pos]-'0))
            ans += calc(pos+1,1,r);
            else if( i == r[pos] - '0) 
            ans += cal(pos+1,0,r);
        } 
    }else{
        for(int i=2;i<10;i+=2){
             if(small || (i< r[pos]-'0))
            ans += calc(pos+1,1,r);
            else if( i == r[pos] - '0) 
            ans += cal(pos+1,0,r);
        }
    }
    return ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r;
        int ans = calc(0,0,r);
        int 

    }
}