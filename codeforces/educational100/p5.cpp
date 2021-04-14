#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n,vector<int>(n));
        rep(i,0,n){
            rep(j,0,n){
                cin>>vec[i][j];
            }
        }
        int rowerro = 0;
         int colerror = 0;
         bool rowinversion = false;
         bool colinversion = false;
        string s;
        cin>>s;
        for(int i=0;i<m;i++){
            if(s[i]=='R'){
                   colerror = colerror - (colinversion==false?1:-1);
                   colerror=(n+colerror)%n;
            }else if(s[i]=='L'){
                colerror = colerror - (colinversion==false?-1:1);
                colerror=(n + colerror)%n;
            }else if(s[i]=='D'){
                rowerro = rowerro - (rowinversion==false?1:-1);
                rowerro = (rowerro + n)%n;
            }else if(s[i]=='U'){
               rowerro = rowerro - (rowinversion==false?-1:+1);
               rowerro= (rowerro + n)%n;
            }else if(s[i]=='I'){
                rowinversion = !rowinversion;
                rowerro = n-1 - rowerro;
            }else {
                colinversion = !colinversion;
                colerror = n-1- colerror;
            }
        }
        //  cout<<rowerro<<" "<<rowinversion<<" \n";
        // cout<<colerror<<" "<<colinversion<<" \n";
        
        for(int i=rowerro, count = 0;count<n;i=(i+n+ (rowinversion==false?1:-1))%n, count++){
            for(int j=colerror, k = 0;
                k<n;j = (j+n+ (colinversion==false?1:-1))%n, k++){
                    // cout<<i<<" "<<j<<endl;
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
       
    
    }
    return 0;
}