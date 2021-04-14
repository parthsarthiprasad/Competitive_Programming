#include<bits/stdc++.h>
using namespace std;
#define forn for(int i=0;i<n;i++)
void reversed(string &s, int start, int end ){
    while(start<end){
        swap(s[start++],s[end--]);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count0 = 0;
        int count1 = 0;
        for(int i=0;i<n-1;i++){
            
            if(s[i]==s[i+1] && s[i]=='0')count0++;
            if(s[i]==s[i+1] && s[i]=='1')count1++;

        }
        cout<<(count0 + count1+1)/2<<endl;
        
    }
}