#include<bits/stdc++.h>
using namespace std;
#define forn for(int i=0;i<n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(l*2>r)cout<<"YES\n";
        else cout<<"NO\n";
    }
}