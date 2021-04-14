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
        vector<int64_t> vec(2*n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int even = 0, odd = 0;
        for(int i=0;i<n;i++){
            if(vec[i]&1) odd++;
            else even++;
        }
        if(odd&1){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
             
        
    }
    return 0;
}