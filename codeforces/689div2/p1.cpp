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
        string kp ="abc";
        int pos = 0;
        for(int i=0;i<n;i+=k){
            for(int j=i; j<n && j<i+k;j++){
                cout<<kp[pos];
            }
            pos++;
            pos%=3;
        }
        cout<<endl;
    }
    return 0;
}