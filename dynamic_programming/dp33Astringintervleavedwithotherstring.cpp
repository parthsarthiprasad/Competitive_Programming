//check if a string is intervleaved
#include<bits/stdc++.h>
using namespace std;
bool findrecur(string &a,string &b,string &c, int indexa=0 , int indexb = 0, int indexc = 0){
    if(indexa==a.size()) return true;
    bool ans = false;
    if(b.size()!=indexb && a[indexa]==b[indexb]){
        ans= ans || findrecur(a,b,c,indexa+1,indexb+1,indexc);
    }
    if(!ans && (c.size()!=indexc && a[indexa] == c[indexc])){
        ans = ans|| findrecur(a,b,c,indexa+1,indexb,indexc+1);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,c;
    cin>>a>>b>>c;
    if(findrecur(a,b,c)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}