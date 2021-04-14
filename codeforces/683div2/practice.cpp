#include<bits/stdc++.h>
using namespace std;
int findanswer(int index, string l, string r, bool small ){
    if(index==l.size()) return 1;
    int answer = 0;
    if(small){
        int i = (l[index] - '0');
        if(((index^i)^1)) i++;
        for(;i<10;i+=2){
            answer+= findanswer(index+1,l,r,small);
        }
    }else{
        int i = (l[index] - '0');
        if(((index^i)^1)) i++;
        for(;i<=(r[index]-'0');i+=2){
            if(i==(r[index]-'0')) answer+= findanswer(index+1,l,r,!small);
            else answer+= findanswer(index+1,l,r,small);
        }
    }
    return answer;
}
int solve(){
    string l,r; 
    cin>>l>>r;
    string ch(r.size() - l.size(), '0');
    l = ch + l;
    int answer  = findanswer(0,l,r,false);
    return answer;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n =1;
    while(t--){
        cout<<"Case #"<<n++<<": "<<solve()<<endl;
    }
    return 0;
}