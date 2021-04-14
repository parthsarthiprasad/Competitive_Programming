#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
// https://www.youtube.com/watch?v=mdr2eLAAPuw&ab_channel=PickleRick
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y) {
            cout<<2*x<<endl;
            continue;
        }
        if(x<y) swap(x,y);
        int ans = min(x,y)*2;
        x-=y;
        
        ans+= 2*x-1;
        cout<<ans<<endl;

    }
    return 0;
}