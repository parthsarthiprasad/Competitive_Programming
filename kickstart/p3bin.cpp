#include<bits/stdc++.h>
using namespace std;
void display(int ptr[], int n){
    for(int i=0;i<n;i++){
	cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
void display(vector<int> vec){
    for(auto a:vec){
    	cout<<a<<" ";
    }
    cout<<endl;
}
bool isvalid(int ptr[], int n, int mid, int k){
    //we've to divide in segments of min size ==mid;
    int count = 0;
    for(int i=1;i<n;i++){
        count+= ((ptr[i]-1)/mid);
    }
    return (count<=k);
}
int solve(){
    int n,k;
    cin>>n>>k;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
	int start = 1;
        int end = ptr[n-1];
    for(int i=n-1;i>0;i--) ptr[i]-=ptr[i-1];
    
    while(start<end){
        int mid =(end+start)/2;
        if(isvalid(ptr,n,mid,k)){
            end = mid;
        }else{
            start = mid+1;
        }
    }
    return start;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;
}
