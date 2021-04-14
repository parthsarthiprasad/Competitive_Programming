#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int prev = n;
        while(n%2==0){
            n/=2;
        }
        if(n!=1 ){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
}