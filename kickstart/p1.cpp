#include<bits/stdc++.h>
using namespace std;
// int solve(){
//     int n,b,temp;
//     cin>>n>>b;
//     int ptr[b+1];
//     memset(ptr,0, sizeof(ptr));
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         for(int i=b;i-temp>-1;i--){
//             ptr[i] = max(ptr[i],1 + ptr[i-temp]);
//         }
//     }
//     return ptr[b];
    
// }

int solve(){
    int n,b,temp;
    cin>>n>>b;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr, ptr+n);
    int i=0, sum=0;
    for(;i<n && sum<=b;sum+=ptr[i], i++);
    if(sum<=b) return i;
    else if(i==0) return 0;
    return i-1;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<"\n";
    }
    return 0;
}