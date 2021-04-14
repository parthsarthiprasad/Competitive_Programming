#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll solve(){
    int n,temp;
    cin>>n;
    int ptr[101];
    memset(ptr,0,sizeof(ptr));
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ptr[temp]++;
    }
    int sum = 0;
    int i=0;
    for(;i<101;i++){
        if(ptr[i]){
            ptr[i]--;
            continue;
        }
        sum+=i;
        break;
    }
    if(sum==0 && i){
        sum=101;
    }
    i=0;
    for(;i<101;i++){
        if(ptr[i]){
            ptr[i]--;
            continue;
        }
        sum+=i;
        break;
    }
    return sum;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}