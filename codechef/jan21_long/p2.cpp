#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.rbegin(), vec.rend());
        int64_t len1 = 0, len2 = 0;
        int i = 0;
        int count = 0;
        for(;i<n;i++){
            if(len1>=k && len2>=k) break;
            if(len1<len2) swap(len1,len2);
            len2+=vec[i];
            count++;
        }
        cout<<i<<" "<<count<<endl;

    }
}