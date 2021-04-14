#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(auto &a:vec)cin>>a;
    // sort(vec.begin(),vec.end());
    vector<int> primes;
    vector<bool> sieve(1e6,false);
    for(int i=2;i*i<1e6;i++){
        if(sieve[i]==false){
            primes.push_back(i);
            for(int j=2;j*i<1e6;j++){
                sieve[j*i] = true;
            }
        }
    }
    primes.push_back(1);
    sort(primes.begin(),primes.end());
    unordered_map<int,vector<int64_t>> dp;
    unordered_map<int,int>> charcount ;
  
    int64_t ans = 0;
    for(int i=0;i<n;i++){
        if(dp.find(vec[i])==dp.end()){
            dp[vec[i]] = vector<int64_t>(primes.size(),1);
        }
        for(int j=0;j<primes.size();j++){
            if(vec[i]%primes[j]==0 &&
                dp.find(vec[i]/primes[j])!=dp.end()){
                dp[vec[i]][j] = 1 + dp[vec[i]/primes[j]][j];
                if(dp[vec[i]][j]>=k){
                    cout<<vec[i]<<" "<<primes[j]<<endl;
                    ans++;
                    ans%=mod;
                }
            }
        }
    }
    cout<<ans<<endl;
    // cout<<primes.size()<<endl;
    return 0;
}