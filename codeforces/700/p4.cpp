#include<bits/stdc++.h>
using namespace std;
const int nax = 102;
vector<int> G[nax];
void dfs(int node, vector<int> &depth, int d){
    depth[node] = d;

    for(auto a:G[node]){
        dfs(a,depth,d+1);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){G[i].clear();}
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[vec[i]] = i;
        }

        vector<int> nextgreaterleft(n,INT_MAX);
        vector<int> nextgreaterright(n,INT_MAX);
        stack<int> s;
        s.push(vec[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&& s.top()<vec[i]){
                s.pop();
            }
            if(!s.empty()){
                nextgreaterright[i] = s.top();
            }
            s.push(vec[i]);
        }
        while(!s.empty()){
            s.pop();
        }
    
        s.push(vec[0]);
        for(int i=1;i<n;i++){
            while(!s.empty() && s.top()<vec[i]){
                s.pop();
            }
            if(!s.empty()){
                nextgreaterleft[i] = s.top();
            }
            s.push(vec[i]);
        }
        // cout<<"*******************************************\n";

        // for(int i=0;i<n;i++){
        //     cout<<nextgreaterleft[i]<<" "<<vec[i]<<" "<<nextgreaterright[i]<<endl;
        // }
        // cout<<"*******************************************\n";
        for(int i=0;i<n;i++){
            // if(vec[i]==n) continue;
            int node = min(nextgreaterleft[i], nextgreaterright[i]);
            if(node == INT_MAX) continue;
            G[node].push_back(vec[i]);
        }

        
        vector<int> depth(n+2,0);
        dfs(n,depth,0);
        for(auto a:vec){
            cout<<depth[a]<<" ";
        }
        cout<<endl;
    }

}