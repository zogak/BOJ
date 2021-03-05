/*camping*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
int l = 0, p = 0, v = 0;
int day = 0;
vector<int> d;
int main() {
	while (1) {
		day = 0; //reset
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		while (v >= p) {
			v = v - p;
			day += l;
		}
		if (v >= l) {
			day += l;
		}
		else {
			day += v;
		}
		d.push_back(day);
	}
	for (int i = 0; i < d.size(); i++) {
		printf("Case %d: %d\n", i + 1, d[i]);
	}
	return 0;
}