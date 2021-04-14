#include<bits/stdc++.h>
using namespace std;
long long int factorials(int num){
    long long int answer = 1;
    for(int i=2;i<=num;i++){
        answer*=i;
    }
    return answer;
}
long long int findcn(int start, int base){
    long long int answer = 1;
    for(int i=0;i<base;i++){
        answer*=(start-i);
        answer/=(i+1);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //formula is ncn/2 fac(n-1)fac(n/2)
    long long int factorial = factorials((n-1)/2);
    factorial = factorial*factorial;
    long long int numerator = findcn(n,n/2);
    if(factorial%2==0){
        factorial/=2;
    }else{
        numerator/=2;
    }
    // cout<<numerator<<" "<<factorial<<endl;
    cout<<numerator*factorial<<endl;
    return 0;
}