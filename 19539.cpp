/*apple trees*/
#include<iostream>
using namespace std;
int n, h, sum, cnt;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		sum += h;
		cnt += h / 2;
	}
}
bool isPossible() {
	if (sum % 3 != 0) {
		return false;
	}
	else {
		if (cnt < (sum / 3)) {
			return false;
		}
		return true;
	}
}
int main() {
	input();
	if (isPossible()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}