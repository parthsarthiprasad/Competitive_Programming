#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s[0]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0')cout<<"YES\n";
        else if(s[0]=='2' && s[1]=='0' && s[n-2]=='2' && s[n-1]=='0')cout<<"YES\n";
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0')cout<<"YES\n";
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0')cout<<"YES\n";
        else if(s[n-4]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0')cout<<"YES\n";
        else cout<<"NO\n";




        
    }
    return 0;
}