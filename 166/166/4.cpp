// InterviewBit template

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <utility>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>

using namespace std;

int minFlips(vector<vector<int>>& mat) {
	string str = "";
	for (auto a : mat) {
		for (auto b : a) {
			str += b + '0';
		}
	}
	queue<string> Q;
	unordered_set<int> set;
	Q.push(str);

	cout << str << '\n';
	return 0;
}


int main() {
	//int n;
	vector<vector<int>> A(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int ans = minFlips(A);
	cout << ans << '\n';
	system("pause");
	return 0;
}
