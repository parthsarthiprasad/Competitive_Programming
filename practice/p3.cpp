#include<bits/stdc++.h>
using namespace std;

long long int solve(){
   int n;
   cin>>n;
   vector<int64_t> vecx(n), vecy(n);
   for(int i=0;i<n;i++){
       cin>>vecx[i];
       cin>>vecy[i];
   }
   sort(vecy.begin(), vecy.end());
   long long int count = 0;
//    int median = (vecy[(n-1)/2] + vecy[n -1 - (n-1)/2])/2;
    int64_t median = vecy[(n-1)/2];
   for(int i=0;i<n;i++){
       count+= abs(vecy[i]-median);
   }
   sort(vecx.begin(), vecx.end());
   for(int i=0;i<n;i++){
       vecx[i]-=i;
   }
    // median = (vecx[(n-1)/2] +vecx[n-1 - (n-1)/2])/2;
    median = vecx[(n-1)/2];
    for(int i=0;i<n;i++){
        count+=abs(vecx[i] - median);
    }
    return count;
   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int i=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;

}