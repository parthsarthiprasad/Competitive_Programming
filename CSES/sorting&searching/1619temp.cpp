#include<bits/stdc++.h>
using namespace std;
struct movie{
    int start;
    int end;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    int64_t maxsum = INT_MIN, sum=0;
    for(int i=0;i<n;i++){
        sum+=vec[i];
        maxsum = max(maxsum,sum);
        if(sum<0)sum=0;
    }
    cout<<maxsum<<endl;
 return 0;   
}