#include<bits/stdc++.h>
using namespace std;
int memo[501][501];
int minmoves(int a,int b){
    if(a<b) swap(a, b);
    if(memo[a][b]!=-1) return memo[a][b];
    if(a==1 || b==1){
        return (memo[a][b] = max(a,b) - min(a,b));
    }if(a==b) return memo[a][b]=0;
    if(a<=0 || b<=0) return 15000;
    
    
    int val = INT_MAX;
    for(int i=1;i<=b;i++){
        val = min(val, minmoves(a-i,b) + minmoves(b,i));
    }
    return (memo[a][b] = 1 + val);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){ memo[i][j]=-1;}
    }
    cout<<minmoves(a,b)<<endl;
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;j++) cout<<memo[i][j]<<" "; 
        cout<<endl;
    }
}