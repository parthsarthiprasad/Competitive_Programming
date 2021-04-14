//codeforces rotation matching
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a,b,vec(n,0);
    map<int,int> temp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp-1);
        vec[a[i]]=i;
    }
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        b.push_back(temp-1);
    }

    for(int i=0;i<n;i++){
        int cur = (vec[b[i]]-i + n)%n;
        temp[cur]++;
    }
    int ans=0;

    for(int i=0;i<n;i++){
        cout<<vec[i];
    }
    map<int,int>::iterator it;
    cout<<endl;
    for(it=temp.begin(); it!=temp.end(); ++it)
        ans=max(ans,it->second);
    cout<<ans<<endl;
    
    return 0;
}