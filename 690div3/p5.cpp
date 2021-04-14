#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
const int mod = 1e9+7;
const int nax =2e5+1;
int64_t factorial[nax];
int64_t pow(int64_t a, int64_t b){
    int64_t res = 1;
    a = a %mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        b = b>>1;
        a = (a*a)%mod;
    }
    return res;
}
int64_t invmod(int n){
    return pow(n, mod-2);
}
int64_t findfactorial(int n, int r){
    // return (factorial[n] *((invmod(factorial[k], mod) * invmod(factorial[n-k],mod))
    // cout<<n<<" "<<r<<endl;
    if(n<r) return 0;
    r = min(r, n - r);
    if(r==0) return 1;
    return (factorial[n] * invmod(factorial[r])) % mod
            * invmod(factorial[n-r])%mod
            % mod;
    // return (factorial[n]*((invmod(factorial[r]) * invmod(factorial[n-r])) % mod)) % mod; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    factorial[0] = 1;
    for(int i=1;i<=2e5;i++){
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        sort(vec.begin(), vec.end());
        int64_t ptr1 = 0;
        int64_t ptr2 = m-1;
        int64_t count = 0;
        while(ptr1<n-m+1 && ptr2<n){
            if(ptr2-ptr1<m-1) ptr2++;
            else if(vec[ptr2] - vec[ptr1]<=k){
                int64_t fval = findfactorial(ptr2 - ptr1, m-1);
                fval=(fval+mod)%mod;
                // cout<<fval<<endl;
                count+= fval;
                count%=mod;
                ptr2++;
            }else{
                ptr1++;
            }
        }
        ptr2 = n-1;
        while(ptr1<n-m+1){
            if(vec[ptr2] - vec[ptr1]<=k){
                int64_t fval = findfactorial(ptr2 - ptr1, m-1);
                fval=(fval+mod)%mod;
                // cout<<fval<<endl;
                count+= fval;
                count%=mod;
            }
            ptr1++;
        }
        cout<<(count+mod)%mod<<endl;

        
    }
    return 0;
}