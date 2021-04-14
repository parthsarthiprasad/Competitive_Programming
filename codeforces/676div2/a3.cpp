#include<bits/stdc++.h>
using namespace std;
long int solve(){
    int w,n;
    cin>>w>>n;
    vector<long long int> wheels(w);
    for(int i=0;i<w;i++)cin>>wheels[i];
    sort(wheels.begin(), wheels.end());
    long long int walk = 1e17;
    for(int i=0;i<w;i++){
        long long int sum = 0;
        int median = (wheels[i+w/2] + wheels[wheels.size()-1-w/2])/2;
        for(int j=i,count=0;count<w;count++,j++){
            sum+= abs(median - wheels[j]);
        }
        walk = min(walk,sum);
        wheels.push_back(wheels[i]+n);
    }
    return walk;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i= 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;
}