#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n;
        string s;
        cin>>s;
        int count = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=')')break;
            count++;
        }
        if(count>n-count)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}