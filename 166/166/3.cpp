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

bool divide(int a, int b) {
	return a % b;
}

long long int func(vector<int>& A, int x) {
	long long var = 0;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		int val = A[i];
		bool val_ = !divide(val, x);
		var += val / x + (int)val_;
	}
	return var;
}

int smallestDivisor(vector<int>& nums, int threshold) {
	int begin = 1;
	int end = (int)pow(10, 6);
	while (begin < end) {
		int mid = (begin + end) / 2;
		if (func(nums, mid) <= threshold) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	return begin;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> n;
	int ans = smallestDivisor(A, n);
	cout << ans << '\n';
	system("pause");
	return 0;
}
