/*words sorting*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s;
vector < pair<int, string> > vec;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		vec.push_back({ s.length(), s });
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second << endl;
	}
	return 0;
}