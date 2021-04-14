//last round went bad due to sprinklr mood
//keepcalm and do well, microsoft is ahead;
#include<bits/stdc++.h>
#define ll long long 
const int mod = 1e9+1;
const int max = 2e5+5;
#define pb push_back
#define mp make_pair
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr,ptr+n);
    if(ptr[0]+ptr[1]<=ptr[n-1]){
        cout<<1<<" "<<2<<" "<<n<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}