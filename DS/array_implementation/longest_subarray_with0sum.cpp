//longest array with 0 sum
// Time complexity O(n) , space complexity O(n)
#include<iostream>
#include<unordered_map>
using namespace std;
int findmaxarray(int arr[], int len){
    unordered_map<int,int> presum;

    int sum = 0;
    int max_len = 0;
    for(int i=0;i<len;i++){
        sum+=arr[i];
        if(sum==0){
            max_len = i;
        }
        if(presum.find(sum)==presum.end()){
            presum[sum]=i;
        }
        else{
            max_len = max(max_len,i-presum[sum]);
        }
    }
    return max_len;
}
int main(){
   int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
   int len = sizeof(arr)/sizeof(arr[0]);
   cout<<findmaxarray(arr, len);
    return 0;
}