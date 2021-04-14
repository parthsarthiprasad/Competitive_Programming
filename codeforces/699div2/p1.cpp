#include<bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int m = 0, n= 0;
        int o = 0; int p = 0;
        bool possible = false;
        
        for(int i=0;i<s.size();i++){
           
            if(s[i]=='R'){
                m++;
            }else if(s[i]=='L'){
                o++;
            }else if(s[i]=='U'){
                n++;
            }else{
                p++;
            }
        }

         if(x>=0 && y>=0){
                if(m>=x && n>=y) possible = true;
        }else if(x>=0 ){
                if(m>=x && p>=abs(y)) possible = true;
        }else if(x<0 && y>=0){
                if(o>=abs(x) && n>=y) possible = true;
        }else {
                if(o>=abs(x) && p>=abs(y)) possible = true;
        }
        if(possible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}