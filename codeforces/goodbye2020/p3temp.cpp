#include<bits/stdc++.h>
using namespace std;
bool valid(char a){
    return ( a-'a' <0);
    
}
const int nax = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                s[i] = '?';
                count++;
            }
        }
        for(int i=1;i<s.size()-1;i++){
            if(s[i-1]==s[i+1]){
                if(s[i-1]!='?'){
                    s[i+1] = '?';
                    count++;
                    i++;
                }
            }
        }
        
        cout<<s<<" "<<count<<endl;

    }
    return 0;
}