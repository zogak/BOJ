/*ATM*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 1001
using namespace std;
int n, m;
int t[MAX], d[MAX];
int sum;
int main() {
	//input
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	//sort
	sort(t+1, t+n+1);
	//time
	d[1] = t[1];
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + t[i];
	}
	//sum
	for (int i = 1; i <= n; i++) {
		sum += d[i];
	}
	printf("%d", sum);
	return 0;
}