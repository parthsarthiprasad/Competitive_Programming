#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    //creating a 2-d matrix;
    vector<vector<char> > vec(n,vector<char>(n) );
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) vec[i][j] = 'N';
    }
    
    for(int i=0;i<n;i++) vec[i][i]='Y';
    for(int i=0;i<n;i++){
        int temp=i;
        for(int j=i+1;(a[j]=='Y')&&(b[temp]=='Y')&&(j==i+1||(vec[i][j-1]=='Y'))&& j<n;temp++,j++) vec[i][j]='Y';
    }
    for(int i=n-1;i>=0;i--){
        int temp=i;
        for(int j=i-1;(a[j]=='Y')&&(b[temp]=='Y')&&(j==i-1 || (vec[i][j+1]=='Y'))&&j>-1;temp--,j--) vec[i][j]='Y';
       
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<vec[i][j];
        cout<<endl;
    }
    //cout<<endl;
    
    return;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<":\n";
        solve();
    }
}