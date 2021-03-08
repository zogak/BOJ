/*i love Croatia*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int k, n, t;
char z;
int bomb, sum;
vector < pair <int, char> > vec;
void input() {
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &t, &z);
		vec.push_back({ t, z });
	}
}
int pass(int a) {
	if (a == 8) {
		return 1;
	}
	else {
		return a + 1;
	}
}
int who(int k) {
	bomb = k;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i].first;
		if (sum >= 210) {
			return  bomb;
		}
		if (vec[i].second == 'T') {
			bomb = pass(bomb);
		}
	}
}
int main() {
	input();
	who(k);
	printf("%d", bomb);
	return 0;
}