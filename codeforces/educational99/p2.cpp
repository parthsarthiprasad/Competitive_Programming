#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
vector<int64_t> vec(1e6+5);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    int value = 1;
    int64_t sum =1;
    for(int i=1;i<=(int)1e6;i++){
        while(i<= int (1e6) && i<sum){
            vec[i] = value;
            i++;
        }
        vec[i] = value;
        if(i==sum){
            vec[i-1] = value+1;
        }
        value++;
         sum+=value;
    }
    
    // for(int i=0;i<10;i++){
    //     cout<<i<<" "<<vec[i]<<endl;
    // }
    while(t--){
       int64_t x;
       cin>>x;
       cout<<vec[x]<<endl;
       
    }
    return 0;
}