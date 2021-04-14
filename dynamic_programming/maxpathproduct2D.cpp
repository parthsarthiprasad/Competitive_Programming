//max product path
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m,0)),
                        minproduct(n,vector<int>(m,INT_MAX)),
                        maxproduct(n,vector<int>(m,INT_MIN));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>vec[i][j];
    }
    minproduct[0][0] = maxproduct[0][0] = vec[0][0];

    for(int i=1;i<n;i++){
        maxproduct[i][0] =max(maxproduct[i-1][0]*vec[i][0],
                              minproduct[i-1][0]*vec[i][0]);
        minproduct[i][0] =min(maxproduct[i-1][0]*vec[i][0],
                              minproduct[i-1][0]*vec[i][0]);
    } 
    for(int j=1;j<m;j++){
        maxproduct[0][j] =max(maxproduct[0][j-1]*vec[0][j],
                              minproduct[0][j-1]*vec[0][j]);
        minproduct[0][j] =min(maxproduct[0][j-1]*vec[0][j],
                              minproduct[0][j-1]*vec[0][j]);
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;j++){
            maxproduct[i][j]  = max(maxproduct[i-1][j]*vec[i][j],
                                    minproduct[i-1][j]*vec[i][j]);
            maxproduct[i][j]  = max({maxproduct[i][j-1]*vec[i][j],
                                     minproduct[i][j-1]*vec[i][j],
                                     maxproduct[i][j]});
            
            minproduct[i][j]  = min(maxproduct[i-1][j]*vec[i][j],
                                    minproduct[i-1][j]*vec[i][j]);
            minproduct[i][j]  = min({maxproduct[i][j-1]*vec[i][j],
                                     minproduct[i][j-1]*vec[i][j],
                                     minproduct[i][j]});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<maxproduct[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<minproduct[i][j]<<" ";
        cout<<endl;
    }                        
    cout<<maxproduct[n-1][m-1]<<endl;



}