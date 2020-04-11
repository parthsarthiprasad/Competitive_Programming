//use of string
#include<bits/stdc++.h>
using namespace std;
///print frequency
void printFrequency(string st){
    //each word is mapped to it's frequency
    map<string,int> ARR;
    stringstream s(st);
    string word;
    while(s>>word)
        ARR[word]++;
    map<string,int>::iterator m; 
    for(m = ARR.begin(); m!=ARR.end();m++)
        cout<<m->first<<" ->  "
            <<m->second<<endl;
    
}
int countWords(string str)
{
    //input is broken in string stream
    stringstream s(str);
    string word;
    int count = 0;
    while(s>>word)
        count++;
    return count;
}

int main(){
    string s = "hello mister how are you who are you "
               "what the fuck is this";
    cout<<" Number of words are "<<countWords(s)<<endl;
    printFrequency(s);
    return 0;
}