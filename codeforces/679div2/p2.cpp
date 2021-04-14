#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define ll long long int 
const int nax = 2e5+5;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> row(n,vector<int>(m));
        vector<vector<int>> col(m,vector<int>(n));
        forn(i,n)forn(j,m)cin>>row[i][j];
        forn(i,m)forn(j,n)cin>>col[i][j];
        vector<int> rotations(n);
        forn(i,n){
            forn(j,n){
                auto it = find(row[j].begin(),row[j].end(),col[0][i]);
                if(it!=row[j].end()){
                    rotations[i] = j;
                    break;
                }
            }
        }
        forn(i,n){
            forn(j,m)cout<<row[rotations[i]][j]<<" ";
            cout<<endl;
        }

       




    }
    return 0;
}