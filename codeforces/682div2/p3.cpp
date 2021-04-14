#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>vec[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i][j] += ((i+j)%2);
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;

        }
    }
    return 0;
}