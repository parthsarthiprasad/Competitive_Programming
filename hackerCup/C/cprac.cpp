#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
struct t{
    int p;
    int h;
    bool operator<(const t &b){
        return p<b.p;
    }
};
void display(t a[],int n){
    for(int i=0;i<n; i++){
        cout<<a[i].p<<" "<<a[i].h<<"\n";
    }
}
ll findsol(){
    int n;
    cin>>n;
    t arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].p;
        cin>>arr[i].h;
    }
    sort(arr,arr+n);
    //display(arr,n);
    map<int,ll> dp;
    // dp[arr[0].p - arr[0].h]=0;
    // dp[arr[0].p]= arr[0].h;
    // dp[arr[0].p+ arr[0].h] = arr[0].h;
    for(int i=0;i<n;i++){
        
        dp[arr[i].p+arr[i].h] = max(dp[arr[i].p+arr[i].h],
                                    dp[arr[i].p] + arr[i].h);

        dp[arr[i].p] = max(dp[arr[i].p -arr[i].h]+arr[i].h,
                            dp[arr[i].p]);
    }
    ll val = 0;
    for(auto a: dp){
        val = max(val,a.second);
    }
    return val;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        printf("Case #%d: %lld\n",i++,findsol());
    }
    return 0;
}