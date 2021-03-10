/*DNA*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
char map[1000][50];
int a, c, g, t, often, cnt;
vector <char> result;
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
}
char change(int a, int c, int g, int t, int often) {
	if (often == a) return 'A';
	if (often == c) return 'C';
	if (often == g) return 'G';
	if (often == t) return 'T';
}
void hammingDistance() {
	for (int i = 0; i < m; i++) {
		a = 0, c = 0, g = 0, t = 0;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 'A') {
				a++;
			}
			else if (map[j][i] == 'C') {
				c++;
			}
			else if (map[j][i] == 'G') {
				g++;
			}
			else if (map[j][i] == 'T') {
				t++;
			}
		}
		often = max(max(a, c), max(g, t));
		result.push_back(change(a, c, g, t, often));
		cnt += n - often;
	}
}
void print() {
	for (int i = 0; i < result.size(); i++) {
		printf("%c", result[i]);
	}
	printf("\n%d", cnt);
}
int main() {
	input();
	hammingDistance();
	print();
	return 0;
}