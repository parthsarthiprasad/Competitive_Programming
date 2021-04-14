#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=n/2;i>=0;i--){
            for(int j=0;j<i;j++){
                cout<<" ";
            }
            // cout<<s<<endl;
            for(int j=1;j<i*2;j++){
                cout<<"*";
            }
            cout<<endl;
        }

    }
    return 0;
}