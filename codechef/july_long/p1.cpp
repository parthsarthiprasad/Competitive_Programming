#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(){
    int n;
    cin>>n;
    ll diff=0;
    int temp;
    cin>>temp;
    for(int i=1;i<n;i++){
        int temp2;
        cin>>temp2;
        diff+= abs(temp-temp2) -1;
        temp=temp2;
    }
    return diff;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}