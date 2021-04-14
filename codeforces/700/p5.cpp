#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
       
        vector<int> sortvec(vec.begin(), vec.end());
        sort(sortvec.begin(), sortvec.end());
        vector<int> prefixsum(sortvec.begin(), sortvec.end());
        for(int i=1;i<n;i++){
            prefixsum[i]+=prefixsum[i-1];
        }
        int breakpointval = -1;
        
        for(int i=0;i<n-1;i++){
            if(prefixsum[i]<sortvec[i+1]) {
                // cout<<prefixsum[i]<<" "<<sortvec[i+1]<<endl;
                breakpointval = sortvec[i+1];
            }
        }
        // cout<<breakpointval<<" breakpoint\n";
        set<int> s;
        // for(int i=0;i<n;i++){
            
        //     int start = (lower_bound(sortvec.begin(), sortvec.end(), vec[i]) - vec.begin());
        //     int end = (upper_bound(sortvec.begin(), sortvec.end(), vec[i]) - vec.begin());
        //     if(sortvec[end-1]>=breakpointval)mp[vec[i]]++;
        // }
        for(int i=0;i<n;i++){
         
            if(vec[i]>=breakpointval){
                s.insert(i+1);
            }
        }
        if(s.size()!=0){
        cout<<s.size()<<endl;
        for(auto a:s){
            cout<<a<<" ";
        }
        cout<<endl;
        }

        
    }
    


}