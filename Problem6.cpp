/*
This problem was asked by Facebook.

Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"

*/
#include <bits/stdc++.h>
using namespace std;

void reverse_string(string str){
	stack<string> st;
	vector<char> v;
	string s = "";
	string pat = "";
	int i;
	for( i = 0; str[i]; i++){
		if(str[i] == '/' || str[i] == ':'){
			v.push_back(str[i]);
			pat+='d';
			if(s!= "")
			st.push(s);
			s = "";
		}
		else{
			if(s==""){
				pat+='s';
			}
			s+=str[i];
		}
	}
	if(str[i-1] != '/' && str[i-1] != ':' && s!= ""){
		st.push(s);
	}
	int j = 0;
	for(int i = 0; pat[i]; i++){
		if(pat[i] == 's'){
			cout << st.top();
			st.pop();
		}
		else{
			cout << v[j];
			j++;
		}
	}
	
}
int main() {
	// your code goes here
	
	string s = "hello//world::here";
	reverse_string(s);
	return 0;
}
