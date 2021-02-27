/*a number plate*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
int result = 1;
int cnt;
void dfs() {
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s[i] == 'd') {
				result *= 10;
				continue;
			}
			else {
				result *= 26;
				continue;
			}
		}
		if (s[i-1] != s[i]) {
			if (s[i] == 'd') {
				result *= 10;
			}
			else {
				result *= 26;
			}
		}
		if (s[i - 1] == s[i]) {
			if (s[i] == 'd') {
				result *= 9;
			}
			else {
				result *= 25;
			}
		}
	}
}
int main() {
	cin >> s;
	dfs();
	cout << result;
	return 0;
}