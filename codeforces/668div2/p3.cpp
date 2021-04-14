#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string solve(){
    int n,k;
    cin>>n>>k;
    string temp;
    cin>>temp;
    for(int i=0;i<k;i++){
        long tosum=0;
        char a='?';
        for(int j=i;j<n;j+=k){
            if(temp[j]=='1' && a=='?'){
                a = '1';
            }else if(temp[j]=='0' && a=='?'){
                a = '0';
            }
            else if(temp[j]=='?') {
                continue;
            }else if(temp[j]!=a ){
                return "NO";
            }
        }
        if(a=='?') continue;
        for(int j=i;j<n;j+=k){
            temp[j] = a;
        }

    }
     for(int i=0;i+k<=n;i+=k){
        long variation = 0;
        long tosum = 0;
        int j=i;
        for(;j<i+k ;j++){
            if(temp[j]=='?') variation++;
            else if(temp[j]=='1') tosum++;
            else tosum--;
        }

        if(tosum-variation>0 || tosum+variation<0){
            return "NO";
        } 
    }
    return "YES";
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}