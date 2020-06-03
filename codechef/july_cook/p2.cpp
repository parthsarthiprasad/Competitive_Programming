#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(){
    ll  n,m,x,y;
    cin>>n>>m>>x>>y;
    ll ans=0;
    ll halfindex = ((n*m)+1)/2;
    ll halfindex2 = ((n*m)/2);
    ll halffillval = 0;
    ll halffillval2 = 0;
    if(y>x ){
        halffillval=x;
        halffillval2 = min(y-x,x);
    }
    else{
        halffillval=y;
        halffillval2=0;
    }
    ll firsthalf = halfindex*halffillval;
    ll secondhalf = halfindex2*halffillval2;
    ans+=firsthalf+secondhalf;
   
    // if(y&1){
    //     if((y+1)/2 >x){
    //         ans = n*m*x;
    //     }else{
    //     ans = (((m*n)+1)/2)*(y+1)/2;
    //     ans+= (y/2)*((n*m)/2);
    //         }
            
    //     }
    // }else 
    // {
    //     ans = n*m*min(x,y/2);
    // }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}