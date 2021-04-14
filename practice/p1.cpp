#include<bits/stdc++.h>
using namespace std;
long long int solve(){
    long long int l,r;
    cin>>l>>r;
    long long int count = 0;
    string num1 = to_string(l);
    string num2 = to_string(r);
    int tempcount = 1;
    int i =0;
    for(;i<num1.length() && num1[i]==num2[i];i++);
    num1 = num1.substr(i);
    num2 = num2.substr(i);
    cout<<num1<<" "<<num2<<endl;
    return 0;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int i=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;

}