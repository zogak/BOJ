/*make to '1'*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm> 
#define MAX 1000001
using namespace std;

int d[MAX];
int n = 0;

void input() {
	scanf("%d", &n);
}
int makeOne(int x) {
	for (int i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;

		if (i % 3 == 0) {
			d[i] = min(d[i], d[i / 3] + 1);
		}
		if (i % 2 == 0) {
			d[i] = min(d[i], d[i / 2] + 1);
		}
	}
	return d[x];
}
int main() {
	input();
	printf("%d", makeOne(n));
	return 0;
}