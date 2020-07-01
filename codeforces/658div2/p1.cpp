#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
void solve(){
    int n,m;
    cin>>n;
    cin>>m;
    map<int,int> vec;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vec[temp]++;
    }
    bool possible = false;
    ll ans;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        if(vec.find(temp)!=vec.end()){
            ans=temp;
            possible=true;
        }
    }
    if(possible){
        cout<<"YES"<<endl;
        cout<<1<<" "<<ans<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}