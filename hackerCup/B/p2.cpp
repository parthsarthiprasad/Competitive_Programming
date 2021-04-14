#include<bits/stdc++.h>
#define ll long long 
using namespace std;

char solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]=='B') count++;
        else count--;
    }
    if(abs(count)>1) return 'N';
    else return 'Y';

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<"\n";
    }
}