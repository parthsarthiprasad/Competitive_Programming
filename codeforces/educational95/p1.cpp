#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        long resticks = (y+1)*k;
        resticks-=(x-1);
        cout<<  1+ (resticks)/(x-1)<<endl;
    }
    return 0;
}