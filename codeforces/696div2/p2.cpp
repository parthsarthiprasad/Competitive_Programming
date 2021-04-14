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
        int count = 0;
        int temp = n;
        while(temp>=2020){
            temp-=2020;
            count++;
        }
        if(temp<=count){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}