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
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        set<int> s;
        for(auto a:vec){
            s.insert(a);
        }
        if(s.size()!=n){
            cout<<"YES"<<endl;
            continue;
        }
        vector<long long int> prefsum(n);
        prefsum[0] = vec[0];
        for(int i=1;i<n;i++) prefsum[i] = prefsum[i-1] + vec[i];
        int prefpos = -1;
        bool possible = false;
        for(int i=0;i<n && !possible;i++){
            if(vec[i]==0){
               if(prefpos==-1){
                   prefpos = i;
                   continue;
               }
               else{
                   if(s.find(prefsum[i]-prefsum[prefpos])!=s.end()){
                       cout<<"YES"<<endl;
                       possible = true;
                       break;
                   }
               }

            }
        }
        if(possible==false){
            cout<<"NO\n";
        }

    }
    return 0;
}