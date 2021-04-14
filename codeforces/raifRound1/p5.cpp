#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);i
    int n,k,temp;
    cin>>n>>k;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        cin>>temp;
        pq.push(temp);
    }
    while(n<k){
        int val = pq.top();
        pq.pop();
        pq.push(val/2);
        pq.push((val+1)/2);
        n++;
    }
    cout<<pq.size()<<endl;
    unsigned long long int sum = pq.top()*pq.top();
    pq.pop();
    for(int i=1;i<k;i++){
        temp = pq.top();
        pq.pop();
        sum+=temp*temp;
    }
    cout<<sum<<endl;
    return 0;
}