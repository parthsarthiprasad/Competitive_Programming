#include<bits/stdc++.h>
using namespace std;
void stockBuySell(int price[], int n){
    if(n==1) return ;
    int i=0;
    while(i<n-1){
        while(i<n-1 && price[i+1]<=price[i]){
            i++;
        }
        if(i==n-1) break;
        int buy = i++;
        while(i<n && price[i]>=price[i-1]){
            i++;
        }

        int sell =i-1;
        cout<<price[buy]<<" "<<price[sell]<<"\n";
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int price[] ={100, 100, 260, 310, 40, 535, 695};
    //int n = sizeof(price)/ sizeof(price[0]);
    stockBuySell(price,n);
}