#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

string add(string& a, string& b) {
	string ans;
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));
	if (a.size() > b.size())swap(a, b);
	int left = 0;
	for (int i = 0; i < a.size(); ++i) {
		int now = a[i] + b[i] - '0' - '0' + left;
		left = now / 10;
		ans += (now % 10) + '0';
	}
	for (int i = a.size(); i < b.size(); ++i) {
		int now = b[i] - '0' + left;
		left = now / 10;
		ans += (now % 10) + '0';
	}
	if (left) {
		ans += left + '0';
	}
	reverse(begin(ans), end(ans));
	while (!ans.empty() && ans[0] == '0')ans.erase(ans.begin());
	if (ans.empty()) return "0";
	return ans;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
}
