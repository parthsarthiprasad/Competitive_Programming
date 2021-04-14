#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
void solve(){
    int l,r;
    cin>>l>>r;
    if(r<2*l){
        cout<<-1<<" "<<-1<<endl;
    }
    else{
        cout<<l<<" "<<2*l<<endl;
    }
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