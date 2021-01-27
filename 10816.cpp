/*number on cards*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n = 0, m = 0;
int a = 0, b = 0;
vector<int> card;
vector<int> target;
int result[500000] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		card.push_back(a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b);
		target.push_back(b);
	}

	sort(card.begin(), card.end());
	for (int i = 0; i < m; i++) {
		result[i] = upper_bound(card.begin(), card.end(), target[i]) - lower_bound(card.begin(), card.end(), target[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}