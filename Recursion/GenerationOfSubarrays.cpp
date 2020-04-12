////Time complexityO(n^2)
//Better approach than bitmasking to generate all possible subarrays.
#include<iostream>
#include<vector>
using namespace std;
void printSubArrays(vector<int> vec, int start, int end){
    if(end==vec.size())
        return ;
    if(start>end)
        printSubArrays(vec,0,end+1);
    else{
        cout<<"[";
        for(int i=start ; i<=end;i++){
            cout<<vec[i]<<"  ";
        }
        cout<<"]"<<endl;
        printSubArrays(vec,start+1,end);
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {1,2,3};
    printSubArrays(arr,0,0);
    return 0;
}