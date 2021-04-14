// #include<bits/stdc++.h>
// using namespace std;
// const int mod = 1e9+7;
// void solve(){
// int n,m;
// cin>>n>>m;
// int h[n],t[m] , ans[m];
// for(auto &x:h) cin>>x;
// for(auto &x:t) cin>>x;
// sort(h, h+n);
// sort(t,t+m);

// memset(ans,-1, sizeof(ans));
// for(int i=0,j=0,k=0;i<n && j<m ;i++,k++){
//     if(h[i]<=t[j]){
//         ans[k]=h[i];
//         j++;
//     }
// }
// for(int i=0;i<m;i++){
//     cout<<ans[i]<<"\n";
// }

// }
// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     solve();
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int, greater<int>> vec;
    for(int i=0;i<n;i++){
        int va;
        cin>>va;
        vec.insert(va);
    }
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        auto it = vec.lower_bound(val);
        // auto it = lower_bound(vec.begin(),vec.end(),val);
        if(it == vec.end()){
            cout<<-1<<endl;
        }else{
            cout<<*it<<endl;
            vec.erase(it);
        }

    }
    return 0;
}