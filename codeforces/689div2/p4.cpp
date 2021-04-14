#include<bits/stdc++.h>
using namespace std;
void bs(vector<int> &vec, int start, int end, unordered_set<int64_t> &s,
        vector<int64_t> &prefsums){
            if(start>=end) return ;
            s.insert(prefsums[end] - prefsums[start]);
            // if(end-start==1){
            //     s.insert(vec[start]);
            //     s.insert(vec[end]);
            //     return ;
            // }
            int index = upper_bound(vec.begin(), vec.end(), (vec[end-1] + vec[start])/2) - vec.begin();
            // cout<<index<<endl;
            if(index==end) return ;

            bs(vec,start,index,s,prefsums);
            bs(vec, index, end,s,prefsums);
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.begin(), vec.end());
        vector<int64_t> prefsums(n+1,0);
        for(int i=1;i<=n;i++){
            prefsums[i]+= prefsums[i-1] + vec[i-1];
        }
        unordered_set<int64_t> s;
        bs(vec,0,n,s , prefsums);
        // for(auto a:s){
        //     cout<<a<<endl;
        // }
        while(q--){
            int bss;
            cin>>bss;
            if(s.find(bss)!=s.end()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            
        }
    }

}