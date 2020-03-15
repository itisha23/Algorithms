#include <bits/stdc++.h>
using namespace std;

vector<string> func(int n) {
	if(n==1){
		vector<string>v;
		v.push_back("(");
		v.push_back(")");
		return v;
	}

	vector<string>v = func(n-1);
    vector<string>vec;
	
	for(int i=0; i<v.size();i++){
		string s="(";
		s=s+v[i];
		string temp=")";
		temp = temp+v[i];
		vec.push_back(s);
		vec.push_back(temp);
	}
	
	return vec;
	
}

int main() {

	vector<string>vec = func(3);
	for(int i=0; i<vec.size();i++){
		cout<<vec[i]<<endl;
	}
}

