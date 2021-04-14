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
int solve(){
    int n,k;
    cin>>n>>k;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    for(int i=n-1;i>0;i--) ptr[i]-=ptr[i-1];
    ptr[0]=0;
    //display(ptr,n);
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        q.push(ptr[i]);
    }
    for(int i=0;i<k;i++){
        int val = q.top();
        q.pop();
        q.push((val+1)/2);
        q.push((val+1)/2);
    }
    return q.top();
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
