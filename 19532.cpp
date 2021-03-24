/*mathmatics on-line lecture*/
#include<iostream>
using namespace std;
int a, b, c, d, e, f, x, y;
int main() {
	cin >> a >> b >> c >> d >> e >> f;
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (a * i + b * j == c && d * i + e * j == f) {
				x = i;
				y = j;
				break;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}