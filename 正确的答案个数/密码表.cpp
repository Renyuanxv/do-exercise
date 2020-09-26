#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string result;
	vector<string> v1{
	{"ABCD"},
	{"EFGH"},
	{"IJKL"},
	{"MNOP"},
	};
	vector<string> v2{
	{"1111"},
	{"1101"},
	{"1110"},
	{"0101"},
	};

	for (int i = 0,a=0; i < v2.size(); ++i,++a) {
		for (int j = 0,b=0; j < v2[0].size(); ++j,++b) {
			if (v2[i][j] == '0')
				result.push_back(v1[a][b]);
		}
	}

	for (int j = 0,a=0; j <v2[0].size(); ++j,a++) {
		for (int i= v2.size()-1,b=0; i>=0; --i,b++) {
			if (v2[i][j] == '0')
				result.push_back(v1[a][b]);
		}
	}

	for (int i = v2.size()-1, a = 0; i >=0; --i, a++) {
		for (int j = v2.size() - 1, b = 0; j >= 0; --j, b++) {
			if (v2[i][j] == '0')
				result.push_back(v1[a][b]);
		}
	}

	for (int j =v2[0].size()-1,a=0; j >= 0; --j, a++) {
		for (int i=0, b = 0;i<v2.size();++i, b++) {
			if (v2[i][j] == '0')
				result.push_back(v1[a][b]);
		}
	}

	cout << result << endl;
	return 0;
}