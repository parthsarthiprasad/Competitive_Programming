#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        set<int> s;
        rep(i,0,n+m){
            int temp;
            cin>>temp;
            s.insert(temp);
        }
        cout<<n+m-s.size()<<endl;



    }
    return 0;
}