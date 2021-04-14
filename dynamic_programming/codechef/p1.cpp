#include<bits/stdc++.h>
using namespace std;
#define int64_t int
const int mod = 1e9+9;
const int nax = 1e6+1;
vector<int> factorial(nax), facinv(nax), naturalinv(nax);
int findexp(int n,int k){
    return ((factorial[n]*facinv[k])%mod * facinv[n-k])%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    naturalinv[0] = naturalinv[1] = 1;
    for(int i=2;i<=nax;i++) naturalinv[i] = naturalinv[mod%i]*(mod-mod/i)%mod;
    facinv[0] = facinv[1] = 1;
    for(int i=2;i<=nax;i++) facinv[i] = (facinv[i-1]*naturalinv[i])%mod;
    factorial[0]=1;
    for(int i=1;i<=nax;i++){
        factorial[i] = factorial[i-1]*i;
        factorial[i]%=mod;
    }

    while(t--){
        int x;
        cin>>x;
        // value is fac(n)/ (fac(k)*fac(n-k)
        int tval = x/3;
        int dval = x%3;
        if(dval==1){
            tval--;
            dval++;
        }else if(dval==2){
            dval--;
        }
        int sum=0;
        while(tval>=0){
            sum += findexp(tval+dval,tval);
            (sum+=mod)%=mod;
            tval-=2;
            dval+=3;
        }
        cout<<sum<<endl;

    }
}