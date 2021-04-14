#include<bits/stdc++.h>
using namespace std;
#define int int64_t
string x,y;
// int findans(int i, int j, int count)
// {
 
//     if (i == 0 || j == 0)
//         return count;
 
//     if (a[i - 1] == b[j - 1]) {
//         count = findans(i - 1, j - 1, count + 1);
//     }
//     count = max(count,
//                 max(findans(i, j - 1, 0),
//                     findans(i - 1, j, 0)));
//     return count;
// }

int longestsub(int n,int m){
    int lcs[n+1][m+1];
    int result=0;//store the maximum value of 2d array
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                lcs[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
            lcs[i][j]=1+lcs[i-1][j-1];
            result =max(result,lcs[i][j]);
            }
            else lcs[i][j]=0;
        }
    }
    return result;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int ans = longestsub(x.size(), y.size());
        cout<<x.size()+y.size() - 2*ans<<endl;
    }
}