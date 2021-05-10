#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

string mul(string& x, string& y) {

	int* a = new int[x.size() + 1]{ 0 };
	int* b = new int[y.size() + 1]{ 0 };
	int* ans = new int[x.size() + y.size() + 2]{ 0 };
	string res;
	
	reverse(begin(x), end(x));
	reverse(begin(y), end(y));

	for (int i = 0; i < x.size(); ++i) {
		a[i] = x[i] - '0';
	}
	for (int i = 0; i < y.size(); ++i) {
		b[i] = y[i] - '0';
	}
	for (int i = 0; i < x.size(); ++i) {
		for (int j = 0; j < y.size(); ++j) {
			ans[i + j] += a[i] * b[j];
		}
	}
	int left = 0;
	for (int i = 0; i < x.size() + y.size(); ++i) {
		int temp = left + ans[i];
		ans[i] = (left + ans[i]) % 10;
		left = temp / 10;
	}
	int i;
	for (i = x.size() + y.size(); i >= 0; --i) {
		if (ans[i] != 0)break;
	}
	if (i < 0)return "0";
	else {
		for (; i >= 0; --i) {
			res += ans[i] + '0';
		}
	}
	return res;
}


int main() {
	string x, y;
	cin >> x >> y;
	cout << mul(x, y) << endl;
}
