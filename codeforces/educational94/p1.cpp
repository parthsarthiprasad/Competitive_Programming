#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string ans="";
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= s[i]-'0';
        }
        if(sum==n){
            ans+='1';
        }else {
            ans+='0';
        }
        int index = n;
        while(index<s.length()){
            sum-=(s[index-n]-'0');
            sum+=(s[index]-'0');
            if(sum==n){
                ans+='1';
            }else{
                ans+='0';
            }
            index++;
        }
        cout<<ans<<endl;
    }
}