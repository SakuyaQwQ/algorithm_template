#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<deque>
#include<map>
#include<unordered_set>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

string add(string a, string b) {
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));
	string res;
	if (a.size() > b.size())swap(a, b);
	int left = 0;
	for (int i = 0; i < a.size(); ++i) {
		int now = a[i] + b[i] - '0' - '0' + left;
		res += (now % 10) + '0';
		left = now / 10;
	}
	for (int i = a.size(); i < b.size(); ++i) {
		int now = b[i] - '0' + left;
		res += (now % 10) + '0';
		left = now / 10;
	}
	if (left) {
		res += left + '0';
	}
	reverse(begin(res), end(res));
	return res;
}


int main() {
	string m, n;
	cin >> m >> n;
	cout << add(m, n) << endl;
}

