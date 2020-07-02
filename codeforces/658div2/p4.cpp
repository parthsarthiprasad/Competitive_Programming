#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
void bitflip(string &s, int end){
    for(int i=0;i<=end;i++){
        if(s[i]=='1'){s[i]='0';}
        else if(s[i]=='0') s[i]='1';
        else{
            cout<<"OHHHHHH";
        }
    }
    int start =0;
    int b = end;
    // while(start<end){
    //     swap(s[start],s[b]);
    //     start++;
    //     end--;
    // }
    reverse(s.begin(),s.begin()+end);
    cout<<"state"<<endl;
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
     cout<<endl;
     return;
}
void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;


    vector<int> ans;
    
    for(int i=n-1;i>-1;i--){
        if(a[i]==b[i]){
            continue;
        }
        else{
            if(a[i]==a[0]){
                bitflip(a,i);
                ans.pb(i+1);
            }else{
                //int j=1;
                // while(a[j]!=a[0] && j<i){j++;}
                // bitflip(a,j);
                // bitflip(a,i);
                // ans.pb(j);
                // ans.pb(i+1);
                bitflip(a,0);
                ans.pb(1);
                bitflip(a,i);
                ans.pb(i+1);
            }
        }
    }
    if(a[0]!=b[0]){ ans.pb(1);}
    cout<<"THE FUCK";
    cout<<ans.size()<<" ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}