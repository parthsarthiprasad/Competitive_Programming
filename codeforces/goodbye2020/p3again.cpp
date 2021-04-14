#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int count = 0;
        for(int i=2;i<n;i+=2){
            if(s[i]==s[i-2]){
                s[i] = '?';
                count++;
            }
        }
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1] && s[i]!='?'){
                s[i] = '?';
                count++;
            }
        }
        cout<<count<<endl;
        
    }
}