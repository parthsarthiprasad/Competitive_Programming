#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;

ll solve(){
    int n, temp;
    cin>>n;
    //int ptr[n];
    int ptr[51];
    memset(ptr,0, sizeof(ptr));
    for(int i=0;i<n;i++){
        cin>>temp;
        ptr[temp]++;
    }
    int count = 0;
    for(int sum=1; sum<=100; sum++ ){
        int val = 0;
        for(int i=max(0,sum-50) ;i<=(sum)/2;i++){
            int  k=0;
            if(ptr[i]!=0 && ptr[sum-i]!=0){
                if(i*2==sum){
                    k = max(k, ptr[i]/2);
                }else{
                    k = max(k, min(ptr[i], ptr[sum-i]));
                }
            }else{
                continue;
            }
            val+=k;
        }
        count = max(count, val);
    }
    return count;

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}