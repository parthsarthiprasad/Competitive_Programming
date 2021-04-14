#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ptr[n], ans[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    for(int i=0;i<n;i++) ans[i]=0;
    stack<pair<int,int> > s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top().first >=ptr[i]) s.pop();
        if(!s.empty()){
           ans[i] = 1 + s.top().second;
        }
         s.push(make_pair(ptr[i],i));
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    //enhances mergesort might work again

}