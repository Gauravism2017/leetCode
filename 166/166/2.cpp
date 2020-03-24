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

vector<vector<int>> groupThePeople(vector<int>& A) {
	unordered_map<int, vector<vector<int>>> map;
	int n = A.size();
	vector < vector<int>> ans;
	for (int i = 0; i < n; i++) {
		if (map.find(A[i]) == map.end()) {
			vector<int> temp;
			vector<vector<int>> _temp;
			temp.push_back(i);
			_temp.push_back(temp);
			map[A[i]] = _temp;
		}
		else {
			vector<vector<int>> _temp = map[A[i]];
			vector<int> _temp_ = _temp[_temp.size() - 1];
			if (_temp_.size() < A[i]) {
				map[A[i]][map[A[i]].size() - 1].push_back(i);
			}
			else {
				vector<int> te;
				te.push_back(i);
				map[A[i]].push_back(te);
			}
		}
	}
	for (auto m : map) {
		for (auto _m : m.second) {
			ans.push_back(_m);
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<vector<int>> ans = groupThePeople(A);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	//cout << ans << '\n';
	system("pause");
	return 0;
}
