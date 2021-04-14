#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define nax 2e5+1
#define mod 1e9+7
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> vec(n);
        long long int sum = 0;
        int temp;
        forn(i,n){
            cin>>temp;
            sum+=temp;
        }
        if(sum==m){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;

}