#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int parent = i;
    int largesttemp = parent;
    int child1 = 2*i +1;
    int child2 = 2*i + 2;
    while(parent<n){
        if(child1<n && arr[parent]<arr[child1]){
            //swap(arr[child1], arr[parent]);
            parent = child1;
        }
        if(child2<n && arr[parent]<arr[child2]){
            //swap(arr[parent],arr[child2]);
            parent = child2;
        }
        if(largesttemp == parent) break;
        swap(arr[largesttemp],arr[parent]);
    }
    return ;
}
void heapsort(int ptr[],int n){
    for(int i=n/2;i>=0;i--)
        heafify(arr,n,i);
    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i)cin>>ptr[i];
    heapsort(ptr,n);
    for(auto x:ptr) cout<<x<<" ";
    cout<<endl;   
}