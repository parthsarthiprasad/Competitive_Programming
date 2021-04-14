#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5+5;
const int mod = 1e9+7;
// int factorial[nax];
// vector<int64_t> factorial(nax);
vector<int64_t> vec(nax);

// int64_t power(inte64_t x, 
//                                   int y, int p)
// {
//     unsigned long long res = 1; // Initialize result
 
//     x = x % p; // Update x if it is more than or
//     // equal to p
 
//     while (y > 0) 
//     {
     
//         // If y is odd, multiply x with result
//         if (y & 1)
//             res = (res * x) % p;
 
//         // y must be even now
//         y = y >> 1; // y = y/2
//         x = (x * x) % p;
//     }
//     return res;
// }
 
// // Returns n^(-1) mod p
// int64_t modInverse(int64_t n,  
//                   int p)
// {
//     return power(n, p - 2, p);
// }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // factorial[0] = 1;

        // for(int i=1;i<=n;i++){
        //     factorial[i] = (factorial[i-1]*n)%mod;
        // }

        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int> counts1(64,0);
        for(int i=0;i<n;i++){
            int j = 0;
            while((1<<j) <= vec[i]){
                if(((1<<j)& vec[i]) == 1){
                    counts1[j]++;
                }
                j++;
            }
        }
        int64_t ans = 0;
        for(int i=0;i<64;i++){
            int64_t tempval = 0;
            tempval = counts1[i]*counts1[i];
            tempval%=mod;
            tempval*=n;
           
            tempval*=(1<<i);
            tempval%=mod;
            ans+=tempval;
            ans%=mod;
        }
        cout<<ans<<endl;
        // for(auto &a:vec)cin>>a;


    }
    return 0;
}