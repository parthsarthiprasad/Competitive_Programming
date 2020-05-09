//Permutation of P(n,k)
/*
P(n,k) = P(n-1,k) + k*P(n-1,k-1)
recursive formula can be used to generate overlapping subproblems 
thus dynamic programming can be used to find the solution..
*/
#include<bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;

ll findpermutation(int n, int k){
    if (k==0||k==n)
    return 1;
    ll ans = findpermutation(n-1,k) + k*findpermutation(n-1,k-1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    cout<<findpermutation(n,k)<<endl;
    return 0;
}