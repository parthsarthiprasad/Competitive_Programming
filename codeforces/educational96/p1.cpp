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
        vector<bool> vec(n+1);
        vec[0] = true;
        // int ptr[3] = {0};
        // if(findrecur(n,ptr)){
        //     cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<endl;
        // }else{
        //     cout<<-1<<endl;
        // }
        for(int i=1;i<=n;i++){
            for(int j : {3,5,7}){
                if(i-j<0) break;
                vec[i] = vec[i] || vec[i-j];
            }   
        }
        int ptr[3] = {0};
        if(vec[n] == false){
            cout<<-1<<endl;
        }else{
            int t = n;
            while(t>0){
                if(vec[t-3]){
                    ptr[0]++;
                    t-=3;
                }else if(vec[t-5]){
                    ptr[1]++;
                    t-=5;
                }else{
                    ptr[2]++;
                    t-=7;
                }
            }
            for(auto a:ptr){
                cout<<a<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}