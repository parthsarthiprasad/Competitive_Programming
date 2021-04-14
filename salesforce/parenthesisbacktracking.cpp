#include<bits/stdc++.h>
using namespace std;
void printstring(int n,int open,int close,string &temp){
//    if(open==close){
//        if(temp.size()!=0)
//        cout<<temp<<endl;
//    }
   if(close==n) {
       cout<<temp<<endl;
       return;
   }
   else{
       if(open>close){
           temp.push_back('}');
           printstring(n,open,close+1,temp);
           temp.pop_back();
       }
       if(open<n){
           temp.push_back('{');
           printstring(n,open+1,close,temp);
           temp.pop_back();
       }
   }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string temp="";
    printstring(n,0,0, temp);
}