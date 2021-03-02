/*lotto*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 13
using namespace std;
int k;
int s[MAX];
int lotto[6];
void dfs(int sIdx, int lottoIdx) {
	if (lottoIdx == 2) {
		for (int i = 0; i < 2; i++) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = sIdx; i < k; i++) {
			lotto[lottoIdx] = s[i];
			dfs(i + 1, lottoIdx + 1);
		}
	}
}
int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &s[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
	return 0; 
}