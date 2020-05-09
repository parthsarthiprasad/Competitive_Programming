//Area under the historgram problem
#include<bits/stdc++.h>
using namespace std;
int findmaxarea(int ptr[], int len){
    stack<int> s;
    int area = INT_MIN;
    int index = 0;
    int temp;



    for(index =0;index<len;++index){

        area=max(area,ptr[index]);

        if(s.empty() || ptr[s.top()]<=ptr[index]){
            s.push(index);
        }
        else{
            while(!s.empty() &&  ptr[s.top()]>=ptr[index]){
                temp=s.top();
                s.pop();
            }
            area=max(area,(index-temp+1)*ptr[index]);
        }
        area = max(area,ptr[index]);
    }
    //cout<<s.top();
    return area;
    // int i=0;
    // while(i<n)
    // {
    //     if(s.empty()||ptr[s.top()<=ptr[index]])
    //     push(i++);
    // }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={6, 2, 5, 4, 5,6, 1, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<findmaxarea(arr,len);
    return 0;
}