#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(){
    string s;
    cin>>s;
    int maxsum=0;
    int n = s.length();
    for(int j=0;j<10;j++){
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]-'0' == j) count++;
    }
    maxsum = max(count,maxsum);
    }
    //now for two sum
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int count=0;
            if(i==j) continue;
               for(int k=0;k<n;k++){
                   if(count&1){
                       if(s[k]-'0'==i) count++;
                   }else{
                       if(s[k]-'0'==j) count++;
                   }
               }
               if(count&1) count--;
               maxsum=max(maxsum,count);
        }
    }
    return n-maxsum;
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