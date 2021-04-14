#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int> > matrix(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) swap(matrix[i][j], matrix[j][i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j] , matrix[i][n-1-j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}