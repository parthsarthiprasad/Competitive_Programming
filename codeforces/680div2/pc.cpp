#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long int p,q;
        cin>>p>>q;
        bool possible = true;
        for(long long int i=1;i<=p && possible;i+=1){
            if((p%i==0) && (p/i)%q){
                cout<<p/i<<endl;
                possible = false;
            }
        }
    }
}