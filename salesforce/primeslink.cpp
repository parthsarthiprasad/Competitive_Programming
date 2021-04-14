#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    int sz = 1000000;
    int sieve[sz];
    sieve[0]=0;
    //sieve[1] =1;
    unordered_map<int,int> primes;
    memset(sieve,-1,sizeof(sieve));
    for(int i=2;i<=sz;i++){
        if(sieve[i]==-1){
            sieve[i] = i;
            primes[(i)]++;
            for(int j=1;j*i<=sz;j++){
                sieve[i*j] = i;
            }
        }
    }
    unordered_map<int,int> answer;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=i;j<min(n,i+6);j++){
            temp+=ptr[j];
            if(primes[temp]!=0){
                answer[temp]++;
            }
            temp*=10;
        }
        //temp/=10;
        // if(primes[temp]!=0){
        //         answer[temp]++;
        // }
    }
    cout<<answer.size()<<endl;
    for(auto a:answer){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}