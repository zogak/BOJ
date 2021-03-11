/*candy game*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 500
using namespace std;
int n, candyR, candyC, result, result1, result2;
char map[MAX][MAX];
char tmp;
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
}
int eat() {
	//row
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				cnt++;
				candyR = max(candyR, cnt);
			}
			else {
				cnt = 1;
			}
		}
	}
	//column
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				cnt++;
				candyC = max(candyC, cnt);
			}
			else {
				cnt = 1;
			}
		}
	}
	return max(candyR, candyC);
}
int changeRow() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				swap(map[i][j], map[i][j + 1]);
				result1 = max(result1, eat());
				swap(map[i][j], map[i][j + 1]);
			}
		}
	}
	return result1;
}
int changeCol() {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] != map[i+1][j]) {
				swap(map[i][j], map[i+1][j]);
				result2 = max(result2, eat());
				swap(map[i][j], map[i+1][j]);
			}
		}
	}
	return result2;
}
int main() {
	input();
	result = max(changeRow(), changeCol());
	printf("%d", result);
}