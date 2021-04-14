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
        int maxsum = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ptr[i];
            maxsum = max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        cout<<maxsum<<endl;
    }
    return 0;
}