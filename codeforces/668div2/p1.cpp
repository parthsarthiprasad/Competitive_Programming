#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++){
        cin>>ptr[i];
    }
    reverse(ptr,ptr+n);
    for(int i=0;i<n;i++)cout<<ptr[i]<<" ";
    cout<<endl;
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}