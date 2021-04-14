#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec;

        rep(i,0,n) {
            int temp;
            cin>>temp;
            if(i>0){
                if(temp==vec[vec.size()-1]){
                    continue;
                }else{
                    vec.push_back(temp);
                }
            }
            else{
                vec.push_back(temp);
            }
        }
        // cout<<endl;
        // for(auto a:vec) cout<<a<<" ";
        // cout<<endl;
        map<int,int> mp;
        n = vec.size();
        rep(i,0,n){
            mp[vec[i]]++;
        }
        int answer = INT_MAX;
        if(vec[0] == vec[n-1]){
            answer = min(answer, -1 + mp[vec[0]]);
        }
        rep(i,0,n){
           
            if(i==0 || i==n-1){
                answer = min(answer,mp[vec[i]]);
            }else{
                answer = min(answer, +1 + mp[vec[i]]);
            }
        }
        cout<<answer<<endl;

        
    }
    return 0;
}