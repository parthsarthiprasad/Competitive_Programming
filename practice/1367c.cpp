#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int count = 0, jump = 2*k ;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                // cout<<jump<<endl;
                count += max(0,(jump-1))/(2*k);
                jump=0;
            }
            else{
                jump++;
            }
        }
        count+= max(0,(jump+k-1))/(2*k);
        cout<<count<<endl;
    }
    return 0;
}