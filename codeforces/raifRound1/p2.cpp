#include<bits/stdc++.h>
using namespace std;
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
        int unreachable = 0;
        int count = 0;
        bool iscycle = true;
        for(int i=0;i<n;i++){
            if(s[i]=='<')count++;
        }
        if(count!=n){
            count = 0;
         for(int i=0;i<n;i++){
            if(s[i]=='>')count++;
            }
            if(count!=n){
                iscycle = false;
            }
        }else{
            cout<<n<<endl;
            continue;
        }
        int stride = 0;
        if(s[s.size()-1]==s[0]){
            while(s[stride]==s[0]){
                stride++;
            }
        }
        bool bval = true;
        for(int i=stride;i<n && bval;i++){
            int j = i;
            int tcount=0;
            while(s[j]==s[i]){
                tcount++;
                j++;
                j%=n;
            }
            unreachable += tcount-1;

            if(j<i){bval = false;}
            i=j-1;
        }
        cout<<n - unreachable<<endl;

    }
    return 0;
}