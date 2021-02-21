/*haven't heard, haven't seen*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
string h, s;
vector<string> v, result;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> h;
		v.push_back(h);
	}
}
void binary(string a) {
	int l = 0; int r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a == v[mid]) {
			result.push_back(a);
			break;
		}
		if (a < v[mid]) {
			r = mid - 1;
		}
		if (a > v[mid]) {
			l = mid + 1;
		}
	}
}
int main() {
	input();
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		binary(s);
	}
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}