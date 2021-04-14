#include<bits/stdc++.h>
using namespace std;
int64_t findanswer( int n, int x,vector<int64_t> &vec, vector<int64_t> &kval, int64_t sum){
    int i = 0;
    while(true){
        if((kval[i]%x)==0){
            sum+=vec[i];
            kval[i]/=x;
        }else{
            break;
        }
        i++;
        i%=n;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int64_t> vec(n);
        vector<int64_t> kval(n,0);
        for(int i=0;i<n;i++)cin>>vec[i];
        int64_t sum = 0;
        for(int i=0;i<n;i++){
            kval[i] = vec[i];
            sum+=vec[i];
        }
        cout<<findanswer( n,x,vec,kval,sum)<<endl;
        // bool turnt  = false;
        // for(int i=0;i<n;i++){
        //     if(kval[i]==minval){
        //         sum+=minval*vec[i];
        //         turnt = true;
               
        //         // break;
        //     }else{
        //         if(turnt){
        //             sum+=vec[i]*minval;
        //         }else{
        //             sum+=kval[i]*vec[i];
        //         }
                
        //     }
        // }
        
        // cout<<sum<<endl;
        
    }
    return 0;
}