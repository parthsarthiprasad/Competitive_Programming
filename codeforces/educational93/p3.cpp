//last round went bad due to sprinklr mood
//keepcalm and do well, microsoft is ahead;
#include<bits/stdc++.h>
#define ll long long 
const int mod = 1e9+1;
const int max = 2e5+5;
#define pb push_back
#define mp make_pair
using namespace std;

ll solve(){
    int n;
    cin>>n;
    int ptr[n+1];
    string s;
    cin>>s;
    ptr[0] = 0;
    ptr[1] = (int)(s[0]-'0');
    for(int i=2;i<=n;i++) ptr[i] = ptr[i-1] + (int)(s[i-1]-'0');
    // for(int i=0;i<=n;i++) cout<<ptr[i]<<" ";
    // cout<<endl;
    int count =0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ptr[j]-ptr[i-1]==j-i+1) count++;
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}