//#include <bits/stdc++.h>
#include<cassert>
#include<cstdint>
#include<iostream>
#include<string>
using namespace std;
bool isletter(char a) {
    return '1' <= a && a <= '9';
}

bool isletter( char a ,char b){
	return (a =='1' && ('0'<=b && b <= '9')) || 
		   ( a == '2'&& ('0'<=b && b <='6') );
}

int64_t decode( const std::string& msg){
	string::size_type len = msg.length();
	if (len == 0) return 1;
	int64_t prev_count = 1 , curr_count = isletter(msg[0]);
	
	for( int i = 1 ; i <len ; ++i){
		int64_t new_count = prev_count * isletter(msg[i-1],msg[i]) + 
							curr_count * isletter(msg[i]);
		prev_count = curr_count ;
		curr_count = new_count;
	}
	return curr_count;
}
int main() {
	assert(decode("25114") == 6);
	assert(decode("3333333333") == 1);
	
	string msg ; 
	cin>>msg;
	cout<<decode(msg)<<endl;
	// your code here

	return 0;
}