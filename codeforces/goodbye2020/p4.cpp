#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5+1;
vector<int> G[nax];
vector<int> weights(nax);
vector<int64_t> answer(nax);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            G[i].clear();
            weights[i] = 0;
        }
        for(int i=0;i<n;i++)cin>>weights[i];
        // for(auto &a:weights)cin>>a;
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int64_t sum = 0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        answer[0] = sum;
        vector<pair<int64_t,int>> sortverti;
        for(int i=0;i<n;i++){
            if(G[i].size()>1){
            sortverti.push_back({weights[i],i});
            }
        }
        sort(sortverti.rbegin(),sortverti.rend());
        int temp = n-2;
        int index = 0;
        int count = 0;
        int vari = 1;
        while(temp>0){
           
            if(count==G[sortverti[index].second].size()-1){
                index++;
                count=0;
            }
             if(index==sortverti.size()){
                 break;
             }
            sum+=sortverti[index].first;
            answer[vari++] = sum;
            count++;
            temp--;
        }
        for(int i=0;i<n-1;i++){
            cout<<answer[i]<<" ";
        }
        cout<<endl;


    }
    return 0;
}