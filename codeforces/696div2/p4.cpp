#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int64_t n,m;
        cin>>n>>m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int j=0;j<n;j++)cin>>b[j];
        vector<int64_t> limp, mimp;
        limp.push_back(0);
        mimp.push_back(0);
        for(int i=0;i<n;i++){
            if(b[i]==1) limp.push_back(a[i]);
            else mimp.push_back(a[i]);
        }

        int64_t sum = 0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum<m){
            cout<<"-1\n";
            continue;
        }else{
            sort(limp.rbegin(), limp.rend());
            sort(mimp.rbegin(),mimp.rend());
        }
        for(int i=1;i<limp.size();i++){
            limp[i]+=limp[i-1];
        }
        for(int i=1;i<mimp.size();i++){
            mimp[i]+=mimp[i-1];
        }
        int conv = 1e17; 
          auto it = upper_bound(mimp.begin(),mimp.end(),m) ;
         auto temp = it;
            temp--;
            if(it!=mimp.begin() && *temp>=m){
                conv = min(conv, (int)(2*(it - mimp.begin())));
            }else if(it!=mimp.end() && *it>=m){
                 conv = min(conv, (int)( 2+  2*(it - mimp.begin())));
            }
           

        for(int i=0;i<limp.size();i++){
            int count = (i+1);
            if(limp[i]>=m){
                conv = min(conv, i+1);
            }
            auto it = upper_bound(mimp.begin(),mimp.end(),m-limp[i]);
            auto temp = it;
            temp--;
            if(it!=mimp.begin() && *temp + limp[i]>=m){
                conv = min(conv,(int) (count + 2*(it - mimp.begin())));
            }else if(it!=mimp.end() && (*it + limp[i]>=m)){
                 conv = min(conv, (int)(count + 2+  2*(int)(it - mimp.begin())));
            }
            // count+= 2*(1+(lower_bound(mimp.begin(),mimp.end(),m-limp[i]) - mimp.begin()));
            // conv = min(conv, count);
        }
        cout<<conv<<endl;
    }
}