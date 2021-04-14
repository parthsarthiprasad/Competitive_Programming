#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;

string solve(){
    int n;
    cin>>n;
    int ptr[n];
    bool ispossible = true;
    for(int i=0;i<n;i++) {
        cin>>ptr[i];
    }
    sort(ptr, ptr+n);
    for(int i=1;i<n;i++){
        if(ptr[i]-ptr[i-1] >1) ispossible = false;
    }
    if(ispossible) return "YES";
    else return "NO";
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}