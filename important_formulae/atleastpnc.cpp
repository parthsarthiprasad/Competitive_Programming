#include<bits/stdc++.h>
using namespace std;
bool valid(string a){
    for(int i=0;i<a.size();i++){
        int count = 0;
        while(i<a.size() && (a[i]=='a'||a[i]=='i'||a[i]=='o'||a[i]=='u')){
            i++;
            count++;
        }
        if(count>=3) return true;
    }
    return false;
}
int main(){
   string a= "alligator";
   sort(a.begin(),a.end());
   int count = 0;
   do{
       if(valid(a)) count++;
   }while(next_permutation(a.begin(), a.end()));
   cout<<count;
       
   
}
