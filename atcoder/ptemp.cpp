#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    int maxdist = ptr[0];
    int count = 0;
    int dist = 0;
    int index=0;
    for(int i=0;i<n;i++){
        if(i<maxdist){
            maxdist=max(maxdist,ptr[i]);
            continue;
        }
        dist += abs(ptr[i]-ptr[index]);
        count++;
        maxdist = ptr[i];
        index =i;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}