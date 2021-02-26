/*push operators*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 11
#define INF 1e9
using namespace std;
int n, p,m,mt,d;
bool v[MAX];
char chosen[MAX];
int arr[MAX];
queue <int> q;
vector<char> tool;
int maxR = -INF;
int minR = INF;
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &p, &m, &mt, &d);
	while (p != 0) {
		tool.push_back('+');
		p--;
	}
	while (m != 0) {
		tool.push_back('-');
		m--;
	}
	while (mt != 0) {
		tool.push_back('*');
		mt--;
	}
	while (d != 0) {
		tool.push_back('/');
		d--;
	}
	
}
void calcul() {
	int tmp = arr[0];
	for (int i = 1; i <= n-1; i++) {
		if (q.front() == '+') {
			tmp += arr[i];
			q.pop();
		}
		else if (q.front() == '-') {
			tmp -= arr[i];
			q.pop();
		}
		else if (q.front() == '*') {
			tmp *= arr[i];
			q.pop();
		}
		else if (q.front() == '/') {
			if (tmp < 0) {
				tmp = tmp * (-1);
				tmp /= arr[i];
				tmp = tmp * (-1);
			}
			else {
				tmp /= arr[i];
			}
			q.pop();
		}
	}
	maxR = max(maxR, tmp);
	minR = min(minR, tmp);
}
void selection(int cnt) {
	if (cnt == n-1) {
		for (int i = 0; i < n-1; i++) {
			q.push(chosen[i]);
		}
		calcul();
	}
	else {
		for (int i = 0; i < n-1; i++) {
			if (v[i] == false) {
				chosen[cnt] = tool[i];
				v[i] = true;
				selection(cnt + 1);
				v[i] = false;
			}
		}
	}
}
int main() {
	input();
	selection(0);
	printf("%d\n", maxR);
	printf("%d", minR);
	return 0;
}