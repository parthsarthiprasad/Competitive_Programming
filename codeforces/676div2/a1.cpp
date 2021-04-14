#include<bits/stdc++.h>
using namespace std;
int solve(){
    string s;
    cin>>s;
    int kick = 0;
    long int answer = 0;
    for(int i=0;i<(int)s.size()-4;i++){
        if(i+5>(int)s.size())break;
        string temp = s.substr(i, 4);
        string temp2 = s.substr(i,5);
        if(temp=="KICK"){
            kick++;
        }else if(temp2=="START"){
            answer+=kick;
        }else{
            continue;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i= 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;
}