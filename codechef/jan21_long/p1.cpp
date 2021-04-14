#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(auto &k:a)cin>>k;
        for(auto &k:b)cin>>k;
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int64_t sum1 = 0;
        int64_t sum2 = 0;
        for(auto k:a)sum1+=k;
        for(auto k:b)sum2+=k;
        int i = 0;
        int j = 0;
        int swaps = 0;
        while(i<a.size() && j<b.size()){
            if(sum1>sum2) break;
            sum1+=b[j];
            sum2+=a[i];
            sum1-=a[i];
            sum2-=b[j];
            swaps++;
            i++;
            j++;
        }
        if(sum1>sum2){
            cout<<swaps<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}