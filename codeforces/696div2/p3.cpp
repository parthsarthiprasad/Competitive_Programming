#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 1e3+3;
#define ll int64_t
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    // build();
    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> ptr1(n);
        for(auto &a:ptr1)cin>>a;
        sort(ptr1.rbegin(),ptr1.rend());
        int count = 1;
        int left = k;
        for(int i=0;i<n && left;i++){
            int j = i;
            int tk = 0;
            while(j<n && ptr1[i]==ptr1[j]){
                j++;
                tk++;
            }
            if(left<tk){
                count = Binomial(tk,left,mod);
            }
             left-=min(left,tk);
        }
        cout<<count<<endl;
    }
}