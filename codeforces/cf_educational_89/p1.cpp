#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solve(int a,int b){
    return max(a/2,b/2);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
       cin>>a>>b;
       cout<<solve(a,b)<<endl;
    }
    return 0;
}