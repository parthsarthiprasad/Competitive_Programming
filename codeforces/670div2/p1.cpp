#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(){
    int n,temp;
    cin>>n;
    map<int,int> mp;
    long sum = 0;
    int count = 0;
    for(int i=0;i<n;++i){
        cin>>temp;
        mp[temp]++;
    }
    
    int prev = 0;
    bool done = false;
    for(auto a:mp){
        if(n%2){
            if(prev!=a.first){
                cout<<prev<<" "<<a.first<<endl;
                sum+=prev;
                return sum;
            }else{
                prev++;
                continue;
            }
        }
        if(a.second<2 && count <2){
            sum+=prev;
            count++;
        }
        prev++;
    }
    if(sum==0) return prev;
    return sum;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}