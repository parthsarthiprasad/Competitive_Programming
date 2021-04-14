#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int answer = 20;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<max(a+b,c+d)<<endl;
        

    }
}