#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
ll solve(){
    int n,k;
    cin>>n;
    vector<ll> vec(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>k;
        vec[i] = k;
        s.insert(k);
    }
    int jump = (find(s.begin(), s.end(), vec[0]) - s.begin());
    for(int i=0;i<n;i++){
        if(i==jump) return vec[i];
        jump = max(jump, find(s.begin(), s.end(),vec[i]) - s.begin());
    }
    return -1;
    
}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
    cout<<solve()<<endl;
    }
    return 0;
}