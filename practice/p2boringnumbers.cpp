#include<bits/stdc++.h>
using namespace std;
long long int solve(){
    long long int l,r;
    cin>>l>>r;
    long long int count = 0;
    string num1 = to_string(l);
    string num2 = to_string(r);
    bool possible = true;
    if(num1.size() !=num2.size()){
        int tk = num2.size() - num1.size();
        num1 = string(tk,'0') + num1;
    }
    long long int tempcount = 1;
    for(int i=0;i<num1.size();i++){
        if(num1[i]==num2[i] )continue;
        if(i&1){
            tempcount*=(min(num2[i]-'0',9)-(num1[i]-'0')/2);
        }else{
            tempcount*=(min(num2[i]-'0',10)-(num1[i]-'0')/2);
        }
    }
    count+=tempcount;
    tempcount = 1;
    for(int i=0;i<num2.size();i++){
        if(num1[i]==num2[i] )continue;
        if(i&1){
            tempcount*=(1+(num2[i]-'0')/2);
        }else{
            tempcount*=(1+(num2[i]-'0')/2);
        }
    }
    count+=tempcount;
    for(int i=0;i<num1.size();i++){
        if(num1[i]==num2[i])continue;
        else{
            num1[i]=num1[i]+1;
            for(int j=i+1;j<num1.size();j++){
                num1[j]='0';
            }
            break;
        }
    }
    for(int i=0;i<num2.size();i++){
        if(num1[i]==num2[i])continue;
        else{
            for(int j=i+1;j<num2.size();j++){
                num2[i]='0';
            }
        }
    }
    cout<<num1<<" "<<num2<<endl;
    // for(int i = l;i<=r;i++){
    //     string temp = to_string(i);
    //     bool possible = true;
    //     for(int j=0;j<temp.size() && possible;j++){
    //          if(((temp[j]-'0')%2)^(j%2)) possible = true;
    //         else possible = false;
    //     }
    //     if(possible) count++;
    // }
    return count;

    // long long int tempcount = 1;
    // int i =0;
    // for(;i<num1.size() && num1[i]==num2[i];i++){
    //     if(num1[i]==num2[i]){
    //         if(num1[i]^(i%2)) possible = true;
    //         else possible = false;
    //         continue;
    //     }
    //     long long int tc = (num2[i]-num1[i]+1)/2;
    //     tempcount*=tc;
    //     // count+=tc*pow(5,num1.size()-1-i);
    // }
    // count+=tempcount;
    // if(possible==false) return 0;
    // cout<<num1.size()<<" "<<num2.size()<<endl;
    // for(auto a:num1)cout<<a;
    // cout<<endl;
    // for(auto a:num2)cout<<a;
    // cout<<endl;
    return count;

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