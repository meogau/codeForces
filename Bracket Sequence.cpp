#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int check(string s){
	stack<char> st;
	for(int i =0;i<s.length();i++){
		if(s[i]=='('||s[i]=='[') {
			st.push(s[i]);
			continue;
		}
		if(st.empty()) return 0;
		switch(s[i]){
			case ')': if(st.top()!='(') return 0; st.pop();break;
			case ']': if(st.top()!='[') return 0; st.pop();break;
		}
	}
	if(st.empty()) return 1;
	return 0;
}
int countBracket(string s){
	int count =0;
	for(int i =0;i<s.length();i++){
		if(s[i]=='[') count ++;
	}
	return count;
}
int main(){

	string  s;
	cin>>s;
	int max =0;
	string ret;
	for(int i =0;i<(s.length()-1);i++){
		string sx ;
		sx.operator+=(s[i]);
		for(int j =i+1;j<s.length();j++){
			sx.operator+=(s[j]);
		//	cout<<"sx : "<<sx<<endl;
			if(check(sx)) {
				if(max <countBracket(sx)||(max==countBracket(sx)&&ret.length()<sx.length())){
					max = countBracket(sx);
				    ret.replace(0,ret.length(),sx,0,sx.length());
				    //cout<<endl<<"ret: "<<ret<<endl;
				   // cout<<endl<<"max: "<<max<<endl;
				    
				} 
			}
		//	cout<<"___________"<<endl;
		}
	}
	cout<<max<<endl;
	if(max!=0) cout<<ret;
}
