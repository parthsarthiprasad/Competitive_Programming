#include<bits/stdc++.h>
#define ll  long long int
using namespace std;


ll solve(){
    int n,k;
    cin>>n>>k;
    k--;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr, ptr+n , greater<int> ());
    int i=k;
        for(;i<n && (i==0 || ptr[i]==ptr[i-1]);i++);
        return i;
}
int main(){
    ll t; cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }

    
    return 0;
}