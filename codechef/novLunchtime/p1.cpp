#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        rep(i,0,n) cin>>vec[i];
        int sum = 0;
        int i = 0;
        int count = 0;
        while(sum>=0 && i<n){
            sum+=vec[i];
            vec[i]=0;
            sum--;
            i++;
            count++;
        }
        count+=sum;
        cout<<count<<endl;

    }
  return 0;  
}