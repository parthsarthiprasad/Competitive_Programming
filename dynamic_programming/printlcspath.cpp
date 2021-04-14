#include<iostream>
#include<string> 
#include<vector>
#include<set>
using namespace std;
set<string> findalllcs(vector<vector<int>> &lcs,int n,
                    int m, string &a, string &b){
    set<string>s;
    if(n==0 || m==0) return s;
    if(a[n-1] == b[m-1]){
        set<string> temp = findalllcs(lcs,n-1,m-1,a,b);
        for(string k:temp){
            s.insert(k+a[n-1]);
        }
    }else{
        if(lcs[n-1][m] >=lcs[m][n-1]){
            s = findalllcs(lcs,n-1,m,a,b);
        }
        if(lcs[n][m-1]>=lcs[n-1][m]){
            set<string> temp = findalllcs(lcs,n,m-1,a,b);
            s.insert(temp.begin(), temp.end());
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        vector<vector<int>> vec(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
                if(a[i-1] == b[j-1]) vec[i][j] = vec[i-1][j-1]+1;
            }
        }

        set<string> answers = findalllcs(vec,n,m,a,b);
        for(auto a:answers) cout<<a<<endl;
    }
}