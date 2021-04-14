#include<bits/stdc++.h>
#include<set>
using namespace std;
const int64_t maxval = 1e18;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define pii pair<int64_t, int64_t>
// int64_t findval(vector<int> &vec, vector<int> & coins, 
//                 int pindex, int64_t cost, int64_t fuel, int indexaccount,
//                 int &maxindex, int & reqdcount){
//     if(fuel<0) return maxval;
//     if(indexaccount==reqdcount) return cost;
//     if(pindex==maxindex) return maxval;
    
//     int64_t sum = min(findval(vec,coins, pindex+1, cost+(coins[pindex]*vec[pindex]),
//                         fuel+ vec[pindex]-1, indexaccount+1, maxindex,reqdcount),
//                  min( findval(vec,coins, pindex+1, cost,
//                         fuel-1, indexaccount+1,maxindex,reqdcount),
//                       findval(vec,coins, pindex+1, coins[pindex]*vec[pindex], vec[pindex]-1,
//                              1, maxindex, reqdcount)    
//                     ));
//     return sum;
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n), coins(n);
        rep(i,0,n) cin>>vec[i];
        rep(i,0,n) cin>>coins[i];
        rep(i,0,n){
            vec.push_back(vec[i]);
            coins.push_back(coins[i]);
        }
        int maxsize = 2*n;
        // int64_t cost = findval(vec,coins,0,0,0,0,maxsize, n);
        int64_t count = 1e18;
        for(int i=0;i<n;i++){
            int64_t tcount = coins[i]*vec[i];
            unordered_set< pii > s;
            int maxdist = vec[i];
            for(int j=i;j<i+n;j++){
                s.insert({coins[i],vec[i]});
                if(maxdist<=j){
                    pair<int64_t, int64_t> pq = *s.begin();
                    s.erase(s.begin());
                     maxdist += pq.first;
                     tcount += pq.second*pq.first;
                }
                
            }
            count = min(count, tcount);
        }
        cout<<count<<"\n";
        
    }
  return 0;  
}