#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int64_t n,x;
        cin>>n>>x;
       
    

        bool possible = false;
        if(x<=n) possible = true;
        for(int i=1;i<=n;i++){
            if(x%i==0 && i<=n && x/i<=n) {
                possible = true;
            }
        }
        if(possible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        
       
    }
    return 0;
}