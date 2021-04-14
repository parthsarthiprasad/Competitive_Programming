#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);

        int sum = 0;
        for(auto &a:vec){
           cin>>a;
           sum+=a;
        }
        int count1 = 0;
        int count2 = 0;
        for(auto a:vec){
           if(a&1) count1++;
           else count2++;
        }
        if(sum&1){
            cout<<"NO\n";
        }else{
            if(count1&1) cout<<"NO\n";
            else if(count1==0 && count2&1)cout<<"NO\n";
            else 
            cout<<"YES\n";
        }

        

    }
    return 0;
}