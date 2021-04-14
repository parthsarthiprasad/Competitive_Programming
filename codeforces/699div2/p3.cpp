#include<bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(n),c(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<m;i++)cin>>c[i];
        map<int,list<int>> mp;
        set<int> s;
        map<int,int> temporary;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                mp[b[i]].push_back(i+1);
            }
            temporary[b[i]] = i+1;
            s.insert(b[i]);
        }


        // for(auto a:mp){
        //     cout<<a.first<<": \t  ";
        //     for(auto b:a.second){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> painter(m);
        if(s.find(c[m-1])==s.end()){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<m;i++){
            if(mp[c[i]].size()!=0){
                //plant the painter should paint
                painter[i] = mp[c[i]].front();
                mp[c[i]].pop_front();
        
            }else if(s.find(c[i])!=s.end()){
                painter[i] = temporary[c[i]];
                //color is present in desired list  
            }else{
                painter[i] = temporary[c[m-1]];
            }
             a[painter[i]-1]  = c[i];
        }
        bool possible = true;
        for(int i=0;i<n;i++){
                if(a[i]!=b[i])possible =false;
            }
        if(possible){
            cout<<"YES\n";
            for(auto a:painter){
                cout<<a<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NO\n";
        }

    }
    return 0;
}