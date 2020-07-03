#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    string a;
    for(int i=0;i<200;i++){
        a+='a';
    }
    cout<<a<<endl;
    for(int i=0;i<n;i++){
        for(int j=vec[i];j<200;j++){
            if(a[j]=='b')
            a[j]='a';
            else a[j]='b';
        }
        cout<<a<<endl;
    }
    // for(int j=vec[n-1];j<200;j++){
    //     a[j]='b';
    // }
    // cout<<a<<endl;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}