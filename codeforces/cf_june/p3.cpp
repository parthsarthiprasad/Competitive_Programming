#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,int>::iterator start1,start2;
    unordered_map<int,int> vec1, vec2;
    int temp=INT_MAX;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        vec1.insert({val,i});
    }
    temp=INT_MAX;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        vec2.insert({val,i});
    }
    //now just simple sliding window3
    start1 = vec1.begin();
    start2 = vec2.find(start1->first);
    int maxcount = 0;
    // cout<<start1->first<<" "<<start1->second<<endl;
    // cout<<start2->first<<" "<<start2->second<<endl;
    
    while(vec1.size()!=0){
        int count = 0;
        cout<<start1->first<<" "<<start1->second<<endl;
        cout<<start2->first<<" "<<start2->second<<endl;
        //int diff = start2->second-start2
        while(vec1.size()!=0 && start1!=vec1.end() && start2!=vec2.end() &&
              start1->first == start2->first){
                  unordered_map<int,int>::iterator temp1,temp2;
                  temp1 = start1++;
                  temp2 = start2++;
            vec1.erase(temp1);
            vec2.erase(temp2);
            // start1=temp1;
            // start2=temp2;
            
            if(start1==vec1.end()) start1 = vec1.begin();
            if(start2==vec2.end()) start2 = vec2.begin();
            cout<<start1->first<<" "<<start1->second<<endl;
            cout<<start2->first<<" "<<start2->second<<endl;

            count++;
        }
        
        if(count>maxcount) maxcount = count;
        if(vec1.size()==0){
            break;
        }
        start2 = vec2.find(start1->first);
       
    }

    cout<<maxcount<<endl;
    return 0;
}