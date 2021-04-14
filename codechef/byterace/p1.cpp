#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k<n){
            cout<<0<<endl;
            continue;
        } else{
        cout<< (k/n)<<endl;
        }
    }
    return 0;
}