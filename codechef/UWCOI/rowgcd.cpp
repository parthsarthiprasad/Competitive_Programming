#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int64_t> a(n);
    
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int64_t ans = 0;
    for(int i=1;i<n;i++){
        ans = __gcd(ans,a[i] - a[0]);
    }
    for(int j=0;j<m;j++){
        int64_t temp, finans;
        cin>>temp;
        finans = __gcd(ans,temp + a[0]);
        cout<<finans<<" ";
    }
    cout<<endl;
    
}