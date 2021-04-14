#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<vector<int>> cache(n,vector<int>(n,0));
    for(int i=0;i<n;++i) cin>>vec[i];
    for(int i=0;i<n;i++){
        cache[i][i] = vec[i];
    }
    for(int gap=1;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            cache[i][i+gap] = min(vec[i] - cache[i+1][i+gap],
                                 vec[i+gap] - cache[i][i+gap-1]);
        }
    }
    long sum = 0;
    sum = accumulate(vec.begin(),vec.end(),0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<cache[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<(sum + abs(cache[0][n-1]))/2;
    return 0;
}