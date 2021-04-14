#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
const int mod = 1e9+7;
#define ll long long 
#define pb push_back
#define mp make_pair
ll solve(){
    int n;
    cin>>n;
    return (n+2)/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}