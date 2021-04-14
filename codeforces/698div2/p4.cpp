#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.begin(), vec.end());
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int start = vec[i]%k;
            mp[start]++;
            int temp = vec[i];
            int amod = 0;
            bool overflow= false;
            int count = 100;
            while(amod!=start && !overflow && count){
                if(temp> 1ll<<62){
                    break;
                }
                temp*=2;
                amod=temp%k;
                count--;
            }
        }
        mp[0]++;
        mp[k]++;
        bool possible = true;
        for(auto a:vec){
            if(mp[k-(a%k)]==0){
                possible = false;
                // cout<<a<<endl;
            }
        }
        if(possible)cout<<"YES\n";
        else cout<<"NO\n";
        // for(int i=0;i<n;i++){
        //     val = __gcd(val,vec[i]);
        // }
        // cout<<val<<" "<<k<<endl;


    }
    return 0;
}

// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
 
// const int maxn=200007;
// int t;
// int n,k;
// int x[maxn];
 
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     cin>>t;
//     while (t--){
//         cin>>n>>k;
//         for (int i=0;i<n;++i) cin>>x[i];
//         sort(x,x+n);

//         int g=0;
//         for (int i=1;i<n;++i){
//             g=__gcd(g,x[i]+x[0]);
//         }
//         cout<<k<<" "<<g<<endl;
//         if ((k+x[0])%g) cout<<"NO\n";
//         else cout<<"YES\n";
//     }
//     return 0;
// }