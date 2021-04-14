#include<bits/stdc++.h>
using namespace std;
bool valid(char a){
    return ( a-'a' <0);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count =0;
        for(int i=0;i<s.size();i++){
            int j = i;
            while(j<s.size() && s[j]==s[i]){
                j++;
            }
            if(j-i>1){
                if(i-2>=0 && s[i-2]==s[i]){
                    for(int k=i;k<j-1;k++){
                        s[k] = 48 + rand()%26;
                }  
                }else{
                for(int k=i+1;k<j;k++){
                    s[k] = 48 + rand()%26;
                }
                }
                count+=(j-i+1)/2;
            }
            i = max(i,j-1);
        }
        // cout<<s<<" ";
        for(int i=0;i<s.size();i++){
            if(i+2>=s.size()) break;
            if(i+2< s.size() && s[i]==s[i+2]){
                count++;
                 s[i+2] = 48 + rand()%26;
            }
        }
        cout<<count<<endl;
        // cout<<s<<" "<<count<<endl;

    }
    return 0;
}