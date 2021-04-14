#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll int64_t

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll w;
        cin>>n>>w;
        vector<pair<int,int>> vec;
        rep(i,0,n) {
            int temp;
            cin>>temp;
            vec.push_back({temp,i+1});
        }
        ll totsum = 0;
        sort(vec.begin() ,vec.end());
        auto it = upper_bound(vec.begin(), vec.end(), w/2 , 
            [](const pair<int,int> &a, const pair<int,int> &b){
                return a.first <b.first;
            });
        if(it->first<=w){
            cout<<1<<endl;
            cout<<it->second <<endl;
        }
        vector<int> answer;
        bool possible = true;
        for(int i=n-1;i>=0;i--){
            if(totsum+ vec[i].first>w) continue;
            else { totsum+=vec[i].first; answer.push_back(vec[i].second);}
            if(totsum>=w/2 ){
                cout<<answer.size()<<endl;
                for(auto a:answer)cout<<a<<" ";
                cout<<endl;
                possible = false;
                break;
            }
        }
        if(possible==true)cout<<"-1\n";
    }
    return 0;

}