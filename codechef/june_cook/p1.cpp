#include<bits/stdc++.h>
using namespace std;
string solve(){
    int s;
    cin>>s;
    string a;
    cin>>a;
    int ptr[26]={0};
    for(int i=0;i<s;i++){
        ptr[a[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(ptr[i]&1)
            return "NO";
    }
    
    return "YES";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}