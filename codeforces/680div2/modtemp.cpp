#include<bits/stdc++.h>
using namespace std;
int main(){
    int n= 100224;
    int mod = 998244353;
    for(int i=1;i<1000;i++){
        long long int val = (n*i)%mod;
        cout<<val<<endl;
    }
    return 0;
}