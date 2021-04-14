#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.begin(),vec.end());
        int minsum = vec[0] + vec[1];
        bool possible = true;
        for(int i=0;i<n;i++){
            if(vec[i]<=d || minsum<=d){continue;}
            else possible = false;
        }
        if(possible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}