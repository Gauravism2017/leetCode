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

int subtractProductAndSum(int n) {
	long long int sum = 0;
	long long int prod = 1;
	int temp;
	while (n) {
		temp = n % 10;
		prod *= temp;
		sum += temp;
		n = n / 10;
	}
	return prod - sum;
}

int main() {
	int n;
	cin >> n;
	int ans = subtractProductAndSum(n);
	cout << ans << '\n';
	system("pause");
	return 0;
}
