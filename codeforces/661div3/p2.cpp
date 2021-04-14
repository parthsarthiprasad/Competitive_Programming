#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;

ll solve(){
    int n;
    cin>>n;
    int a[n],b[n];
     int mina = INT_MAX;
    int minb = INT_MAX;
    for(int i=0 ; i<n;i++) {
        cin>>a[i];
        mina = min(mina, a[i]);
    }
    for(int i=0; i<n;i++) {
        cin>>b[i];
        minb = min(minb, b[i]);
    }
    ll count =0;
    for(int i=0;i<n;i++){
        int diff1 = a[i] - mina;
        int diff2 = b[i] - minb;
        count +=max(diff1, diff2);
    }
    return count;
   
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}