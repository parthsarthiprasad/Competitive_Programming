#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int count1 = 0, count2=0, count3=0;
    for(int i=1;i<s.size();i++){
        count1 += s[i]-s[i-1]>=0?1:0 ;
    }
    for(int i=1;i<s.size();++i){
        count2+= s[i]-s[i-1]<0?1:0;
    }
    // for(int i=1;i<size();i++){
    //     count3+=s[i]==s[i-1]?1:0;
    // }
    cout<<min(count1,count2);
}