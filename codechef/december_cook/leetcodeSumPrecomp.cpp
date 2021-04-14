#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(auto &a:vec)cin>>a;
    vector<vector<int64_t>> sumprecomp(n,vector<int64_t>(sqrt(n),0));
    vector<vector<int64_t>> prodprecomp(n,vector<int64_t>(sqrt(n),1));
    for(int i=0;i<sqrt(n);i++){
        sumprecomp[n-1][i] = vec[n-1];
        prodprecomp[n-1][i] = vec[n-1];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<sqrt(n);j++){
            if(i+j<n){
            sumprecomp[i][j] = (sumprecomp[i+j][j] + vec[i])%mod;
            prodprecomp[i][j] = (prodprecomp[i+j][j] * vec[i])%mod;
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0){
            if(y>=sqrt(n)){
                int64_t val = 0;
                for(int i=x;i<n;i+=y){
                    val+= vec[i];
                    val%=mod;
                }
                cout<<val<<"\n";
            }else{
                cout<<sumprecomp[x][y]<<"\n";
            }
        }else{
            if(y>=sqrt(n)){
                int64_t val = 1;
                for(int i=x;i<n;i+=y){
                    val*=vec[i];
                    val%=mod;
                }
                cout<<val<<"\n";
            }else{
                cout<<prodprecomp[x][y]<<"\n";
            }
        }
    }
    return 0;

}