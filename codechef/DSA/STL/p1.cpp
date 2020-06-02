#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>vec1(n);
        vector<pair<int,int>>vec2(m);
        for(int i=0;i<n;i++){
            cin>>vec1[i].first;
            vec1[i].second=i;
        }
        for(int i=0;i<m;i++){
            cin>>vec2[i].first;
            vec2[i].second=i;
        }
         for(int i=0;i<m;i++){
            cout<<vec1[0].second<<" "<<vec2[i].second<<endl; 
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        for(int i=1;i<n;i++){
            cout<<vec1[i].second<<" "<<vec2[m-1].second<<endl; 
        }
       
        vec1.clear();
        vec2.clear();
        
    }
    return 0;
}