//need practice on these window problems
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr, ptr+n);
    int a = ptr[n/2];
    ll cost = 0;
    for(int i=0;i<n;i++) cost+= abs(ptr[i]-a);
    return cost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve()<<endl;
}