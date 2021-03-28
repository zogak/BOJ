/*bracket*/
#include  <iostream>
#include <stack>
using namespace std;
int t;
string s;
stack <char> st;
void solution(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else { // right
			if (st.empty()) {
				cout << "NO" << endl;
				return;
			}
			else {
				st.pop();
			}
		}
	}
	if (st.empty()) {
		cout << "YES" << endl;
		return;
	}
	else {
		while (!st.empty()) {
			st.pop();
		}
		cout << "NO" << endl;
		return;
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		solution(s);
	}
	return 0;
}