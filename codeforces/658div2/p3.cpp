#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
ll solve(){
    int n;
    cin>>n;
    string a,b;
    vector<int> ans;
    int numflips=0;
    for(int i=n-1;i>-1;i--){
        if((a[i]==b[i]) && !(numflips&1)){
            continue;
        }
        else if(a[i]!=b[i] && numflips&1){
            continue;
        }else{
            ans.pb(i+1);
            numflips++;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
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