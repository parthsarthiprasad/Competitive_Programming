#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int64_t n,gkval;
        cin>>n;
        gkval = n;
        int64_t maxn = 1e5+7;
        vector<int64_t> primes;
        vector<int64_t> ans;
        vector<int> sieve(1e5+8,-1);
        for(int i=2;i<maxn;i++){
            if(sieve[i]==-1){
                primes.push_back(i);
                for(int j=1;j*i<=maxn;j++){
                    sieve[j*i] = i;
                }
            }
        }
     
        int temp = 0;
        while(n>(1LL) && temp<primes.size()){
            while(n%primes[temp]==0){
                ans.push_back(primes[temp]);
                n/=primes[temp];
            }
            temp++;
        }
        if( n!=1){
            ans.push_back(n);
        }
    
        else{
            // for(auto a:ans){
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            map<int64_t, int> mp;
            for(auto a:ans){
                mp[a]++;
            }
            int count = 0;
            int number = 0;
            for(auto a:mp){
                if(a.second>count){
                    number = a.first;
                    count = a.second;
                }
            }
            cout<<count<<" "<<number<<endl;
            vector<int64_t> finans(count,number);
            finans[count-1] = gkval;
            for(int i=0;i<count-1;i++){
                finans[count-1]/=number;
            }
            // for(auto a:mp){
            //     for(int i = count-1, tempval = a.second;i>=0 && tempval>0;i--,tempval--){
            //         finans[i]*=a.first;
            //     }
            // }
            cout<<finans.size()<<"\n";
            for(auto a:finans){
                cout<<a<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}