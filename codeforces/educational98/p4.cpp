#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
const int longmod = 998244353;
int64_t finmodularinverse(int k){
    int64_t a = 1;
    while(k--){
        a*=2;
        a%=longmod;    
    }
    for(int64_t x = 1;x<longmod;x++){
            if((a*x)%longmod ==1){
                return x;
            }
    }
    cout<<"PROBLEM";
    return 0;
}
int64_t finmodularinverse1(int a){
    for(int64_t x = 1;x<longmod;x++){
            if((a*x)%longmod ==1){
                return x;
            }
    }
    return 0;
}
int main(){
   
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<748683265<<endl;
            continue;
        }
        int k = n-3;
        // i want to find modular inverse of 2^(n)
        int64_t val = finmodularinverse(n);
        cout<<val<<"   ";
        int64_t tkval = val;
        tkval += finmodularinverse1(8);
        // tkval%=mod;

        // while(k--){
        //     tkval*=2;
        //     tkval%=longmod;
        // }
        // tkval += val;
        tkval%=longmod;
        cout<<tkval<<endl;

    }
    return 0;
}