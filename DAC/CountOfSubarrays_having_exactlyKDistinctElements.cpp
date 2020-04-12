//count of subarrays having exactly k distincy elements
#include<bits/stdc++.h>
using namespace std;
//Time Complexity O(n) , Space Complexity O(n)
int findkexact(int arr[], int n, int k){
    //here we use the concept of map and sliding window to have at most k distinct elements always
    int count =0;
    int left =0 , right =0;
    map<int,int> table;
    while(right<n){
        //initialize a new point if coming for first time
        if(table.find(arr[right])==table.end())
            table[arr[right]]=0;
        table[arr[right]]++;
        while(table.size()>k){
            table[arr[left]] = table[arr[left]] -1;
            if(table[arr[left]]==0)
                table.erase(arr[left]);
            left++;
        }

        count += right-left+1;
        right++;
    }
    return count;
}

int findkdistinct(int ptr[],int n, int k){
    return findkexact(ptr, n, k) - findkexact(ptr, n, k-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={2,1,2,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    cout<<findkdistinct(arr,size,k);
    return 0;
}