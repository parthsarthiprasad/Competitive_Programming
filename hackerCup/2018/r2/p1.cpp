//pipes
#include<bits/stdc++.h>
using namespace std;
int findans(){
    int a;
    cin>>a;
    const int mod = 1e9+7;
    string mat[3];
    bool ispossible = true;
    int count = 1;
    for(int i=0;i<3;++i){
        for(int j=0;j<a;j++){
            cin>>mat[i][j];
            if(i==1 && mat[i][j]=='#') ispossible = false;
           
        }
    }
    if(mat[0][0] == '#' || mat[1][0]=='#' || 
        mat[2][a-1]=='#' || mat[1][a-1]=='#'){
            ispossible=false;
        }
    for(int i=1;i<a-1 && ispossible;i++){
        if(mat[0][i]=='#' && mat[1][i]=='#'){ ispossible=false; break;}
        if((mat[0][i]=='.' && mat[0][i+1]=='.')&&
           (mat[2][i]=='.' && mat[2][i+1]=='.') )
         count*=2 , count = count%mod;
    }
    if(ispossible) return 0;
    else return count;
    
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t, i =1;
    cin>>t;
    while(t--){
        int val =findans();
        printf("Case #%d: %d\n",i++, val);
    }
    return 0;

}