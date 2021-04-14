#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second<b.second;
}
int solve(){
    int n,a,b;
    cin>>n;
    vector<pair<int,int> >vec;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end(), comp);
    int count =0;
    int enddur=0;
    // for(auto [a,b]:vec){
    //     cout<<a<<" "<<b<<endl;
    // }
    for(int i=0;i<n;i++){
        while(i<n && vec[i].first<enddur){
            i++;
        }
        if(i==n){ break;}
        count++;
        enddur=vec[i].second;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}
/*
3
3 5
4 9
5 8
*/