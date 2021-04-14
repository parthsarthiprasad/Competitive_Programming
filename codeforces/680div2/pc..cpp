#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        if(a%b){
            cout<<a<<endl;
            continue;
        }
        for(long long int i=1;i<=p && p/i>q;i++){
            if(p%i==0 && (p/i)%q){
                cout<<p/i<<endl;
                break;
            }
        }
    }
}