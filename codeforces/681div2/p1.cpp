#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num1 = 4*n;
        for(int i=0;i<n;i++,num1-=2){
            cout<<num1<<" ";
        }
        cout<<endl;
    }
    return 0;
}