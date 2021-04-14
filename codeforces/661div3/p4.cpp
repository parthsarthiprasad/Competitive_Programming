#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> vec;
    
    int ans[n];
    ans[0]=1;
    stack<int> top0;
    stack<int> top1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(top1.size()==0){
                ans[i]= top0.size()+1;
                top0.push(top0.size()+1);
            }else{
                int val = top1.top();
                top1.pop();
                ans[i] = val;
                top0.push(val);
            }
        }else{
            if(top0.size()==0){
                ans[i]= top1.size()+1;
                top1.push(top1.size()+1);
            }else{
                int val = top0.top();
                top0.pop();
                ans[i] = val;
                top1.push(val);
            }
        }
    }
    cout<<top0.size() + top1.size()<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // if(s[0]==0){
    //     sz++;
    // }
    // for(int i=1;i<n;i++){
    //     if(s[i]!=s[i-1]){
    //         if(s[i-1]=='0'){
    //             sum++;
    //         }else{
    //             sum--;
    //         }
    //     }else{
    //         if(sum==0 || sz==sum){
    //             sz++;
    //             if(s[i]=='1') sum++;
    //         }else{
    //             if(s[i]=='1') sum++;
    //             else sum--;
    //         }
    //     }
    // }
    // cout<<sz<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}