//sliding window problem
/*
    Simplifying a nested loop into a single loop
*/
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ptr[]={100, 500, 200, 300, 400};
    int k = 2;
    int maxsum =0;
    int sum =0;
    for(int i=0;i<k;i++){
        sum+=ptr[i];
    }
    int len = sizeof(ptr)/sizeof(ptr[0]);
    for(int i=k;i<len;i++){
        sum = sum + ptr[i] - ptr[i-k];
        if(sum>maxsum)  maxsum=sum;
    }
    cout<<maxsum;
    return 0;
}