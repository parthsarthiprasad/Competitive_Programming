#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> vec(n), tk(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        for(int i=0;i<n;i++)cin>>tk[i];
        sort(vec.begin(), vec.end());
        sort(tk.rbegin(), tk.rend());
        bool possible = true;
        for(int i=0;i<n && possible;i++){
            if(vec[i] + tk[i] >m) possible = false;
        }
        if(possible){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}