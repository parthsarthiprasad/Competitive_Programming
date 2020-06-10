#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
#define mp make_pair
using namespace std;
int return_power(int a){
    int sum=0;
    while(a){
        sum+=a%10;
        a=a/10;
    }
    return sum;
}
pair<int,int> solve(){
    int n;
    cin>>n;
    ll p1=0, p2=0 ;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        a=return_power(a);
        b=return_power(b);
        if(a>=b){
            p1++;
        }
        if(a<=b){
            p2++;
        }
    }
    if(p1>p2){
        return mp(0,p1);
    }
    else if(p2>p1){
        return mp(1,p2);
    }
    else{
        return mp(2,p1);
    }

}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        pair<int,int> p = solve();
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}