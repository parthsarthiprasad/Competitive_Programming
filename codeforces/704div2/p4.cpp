#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        // int minv = vec[0];
        // int maxv = vec[1];
        set<int> s;
        // s.insert(maxv-minv);
        for(int i=0;i<n-1;i++){
            int minv = min(vec[i],vec[i+1]);
            int maxv = max(vec[i],vec[i+1]);
        
            s.insert(maxv - minv);
            for(int j=i+2;j<n;j++){
                if(minv==vec[i] || maxv==vec[i] ) {
                    continue;
                }else{
                    break;
                }
                if(vec[j]>=maxv){
                    minv = maxv;
                    maxv = vec[j];
                }else if(vec[j]>minv){
                    minv = vec[j];
                }
                s.insert(maxv - minv); 
                
            }

        }
        // for(auto a:s){
        //     cout<<a<<" ";
        // }
        cout<<s.size()<<endl;
    }
    
    return 0;
}