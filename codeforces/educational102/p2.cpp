#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s, k;
        cin>>s>>k;
        if(s.size()<k.size())swap(s,k);
        int minsize =  k.size()/__gcd(s.size(),k.size());
        string test="";
        for(int i=0;i<minsize;i++){
            test+=s;
        }
        bool possible = true;
        int minlen = test.size();
        int gksize = k.size()*s.size()/__gcd(k.size(),s.size());
        for(int i=0;i<test.size();i+=k.size()){
            if(test.substr(i,k.size())!=k){
                possible = false;
                break;
            }else{
                if((i+1)%gksize==0) minlen = min(minlen,i+1);
            }
        }
        if(!possible) cout<<"-1\n";
        else {
            cout<<test.substr(0,minlen)<<endl;
        }
        // cout<<test.size()<<" "<<s.size()<<" "<<k.size()<<endl;
        
    }
    return 0;
}