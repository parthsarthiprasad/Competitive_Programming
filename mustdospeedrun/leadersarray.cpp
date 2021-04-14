//leaders in array
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ptr[n];
        for(int i=0;i<n;i++) cin>>ptr[i];
        cout<<ptr[n-1]<<" ";
        int maxsofar = ptr[n-1];
        for(int i=n-2;i>-1;i--){
            maxsofar = max(maxsofar,ptr[i]);
            if(maxsofar == ptr[i]){
                cout<<maxsofar<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}