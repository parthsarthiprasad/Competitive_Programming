#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n+1);
        vec[0] =1;
        for(int i=1;i<=n;i++){
            if(i<k) vec[i] = vec[i-1]+1;
            else vec[i] = vec[i-1]-1;
        }
        vector<int> temp (k);
        for(int i=1;i<=k;i++)temp[i-1] = i;
        vector<int> finans(vec.begin(), vec.end());
        vector<int> finexpr(temp.begin(),temp.end());
        map<int,vector<int>> mp;
        int maxinversion = 0;
        for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(vec[j]>vec[i]) maxinversion++;
                }
            }
        do{
            vector<int> tk(n);
            for(int i=0;i<n;i++){
                tk[i] = temp[vec[i]-1];
            }
            // cout<<"HERE\n";
            // for(int i=0;i<n;i++){
            //     cout<<tk[i]<<" ";
            // }
            // cout<<endl;
            int numinversions = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(tk[j]>tk[i]) numinversions++;
                }
            }
            if(numinversions<=maxinversion){
                bool larger = false;
                for(int i=0;i<n && !larger;i++){
                    if(tk[i]>finans[i]) larger = true;
                }
                if(larger){
                    finans = tk;
                    finexpr = temp;
                    mp[numinversions] = temp;
                }
                if(mp.find(numinversions)==mp.end()){
                    mp[numinversions] = temp;
                }
            }
            for(int i=0;i<k;i++)cout<<temp[i]<<" ";
            // cout<<endl;
            cout<<numinversions<<endl;
        }while(next_permutation(temp.begin(),temp.end()));
        cout<<endl;

        // for(auto a:mp){
        //     cout<<a.first<<endl;
        //     for(auto b:a.second){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(auto a:finexpr)cout<<a<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<finans[i]<<" ";
        // cout<<endl;
    }
    return 0;
}