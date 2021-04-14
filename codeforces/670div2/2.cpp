#include<bits/stdc++.h>
using namespace std;
#define ll long long 
pair<long,long>  findprod(int ptr[], int start, int end){
  vector<int> temp;
  for(int i=start; i<=end;i++){
      temp.push_back(ptr[i]);
  }
  sort(temp.begin(), temp.end());
  int maxprod = max({temp[temp.size()-1] * temp[temp.size()-2],
                    temp[temp.size()-1] * temp[0],
                    temp[0]*temp[1]});
  int minprod = min({temp[temp.size()-1] * temp[temp.size()-2],
                    temp[temp.size()-1] * temp[0],
                    temp[0]*temp[1]});
  return {maxprod, minprod};
}
ll solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i)cin>>ptr[i];
    long maxprod = (long int)-1e30;
    for(int i=2;i<n-3;i++){
        int product = ptr[i];
        pair<long,long> num = findprod(ptr,0,i-1);
        pair<long,long> num2 = findprod(ptr,i+1,n-1);
        maxprod = max({maxprod , product* num.first * num2.first , 
                                 product *num.second * num2.second,
                                 product * num.second *num2.first,
                                 product *num.second * num2.second});
    }
    return maxprod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}