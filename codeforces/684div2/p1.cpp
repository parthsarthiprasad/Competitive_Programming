#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        int count0 = 0 , count1 = 0;
        for(auto a:s){
            if(a=='0') count0++;
            else count1++;
        }
        long long int count = INT_MAX;
        for(int i=0;i<=n;i++){
            long long int val = i*a +(n-i)*b + abs(count0-i)*c;
            count = min(count, val );
        }
        cout<<count<<endl;
        // vector<int> vec(n);
        // rep(i,0,n)cin>>vec[i];
        // for(auto a:vec)cout<<a<<" ";
    }
}