#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        
        for(int i=0;i<n;i++)cin>>vec[i];
        int height = 0;
        queue<int> parent;
        queue<int> children;
        parent.push(vec[0]);
        for(int i=1;i<n;i++){
            children.push(vec[i]);
        }
        while(!children.empty()){
            int sz = parent.size();
            
            for(int i=0;i<sz && !children.empty();i++){
                int currval = parent.front();
                parent.pop();
                do{
                    currval = children.front();
                    parent.push(currval);
                    children.pop();
                }
                while(!children.empty() && children.front()>currval);
            }
            height++;
            if(parent.empty() && !children.empty()){
                parent.push(children.front());
                children.pop();
            }
        }
        cout<<height<<endl;
        // int i = 1;
        // int numnodes = 1;
        // while(i<n){
        //     int tempval = numnodes;
        //     int tempnodes = 0;
        //     while(tempval-->0){
        //         int count = 0;
        //         while(i<n && vec[i]>vec[i-1]){
        //             i++;
        //             tempnodes++;
        //             count++;
        //         }
        //         if(count==0){height+=tempval; tempval=0; tempnodes=1};
                
        //     }
        //     numnodes = tempnodes;
        //     height++;
        //     i++;
        // }
    }
}