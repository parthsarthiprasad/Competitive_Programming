#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    sort(ptr,ptr+n);
    long  sum = accumulate(ptr,ptr+n,0);
    cout<<sum<<" "<<ptr[n-1]*2<<endl;
    cout<<max(sum, ptr[n-1]*2)<<endl;
    return 0;
}