#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+3;
int deg[nax];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        bool possible = true;
        int i = 1;
        while(i<n){
            if(vec[i]>vec[i-1]){
                vec[i] = vec[i] - vec[i-1];
                i++;
                break;
            }
            i++;
        }
        while(i<n && possible ){
            if(vec[i]<vec[i-1]) possible = false;
            i++;
        }
        if(!possible) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}