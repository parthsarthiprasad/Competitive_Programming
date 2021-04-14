#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define nax 2e5+1
#define mod 1e9+7
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    // int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<"1 1\n1 1\n";
            continue;
        }
        vector<vector<int>> vec(n,vector<int>(n,0));
        vec[0][0] = vec[0][1] = vec[1][0] = vec[1][1] = 1;
        for(int i=1;i<n-1;i++){
            vec[i][i-1] = vec[i][i] = vec[i][i+1] = 1;
        }
        vec[n-1][n-1] = vec[n-2][n-1] = vec[n-1][n-2]=vec[n-2][n-2] = 1;
        forn(i,n){
            forn(j,n){cout<<vec[i][j]<<" ";}
            cout<<endl;
        }
    }
    return 0;

}