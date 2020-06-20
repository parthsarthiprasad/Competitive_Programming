#include<bits/stdc++.h>
using namespace std;
int ptr[10001];
int sum[10001];
int n,x;
int findlargest(int startindex,int endindex){
    if(startindex>endindex)
        return 0;
    int length =0;
    if(((sum[endindex]-sum[startindex] + ptr[startindex])%x==0)){
        length=max(findlargest(startindex,endindex-1),findlargest(startindex+1,endindex));
        return length;
    }
    else{
    return endindex-startindex+1;
    }
}
int solve(){
    cin>>n>>x;
    bool flag = true;
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(i!=0)
            sum[i] = sum[i-1];
        sum[i]+=temp;
        ptr[i] = temp;
    }
    int maxsize = 0;
    for(int i=0;i<n;i++){
        if(sum[i]%x){
            maxsize=i+1;
        }
    }

    if (maxsize==0)
        return -1;
    if(maxsize==n)
        return n;

   return findlargest(0,n-1);


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
        
    }
    return 0;
    
}