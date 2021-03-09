/*group word checker*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int n, cnt;
string word;
int check[26];
bool isGroupword(string word) {
	memset(check, 0, sizeof(check));
	if (word.length() == 1 || word.length() == 2) {
		return true;
	}
	else { //단어의 길이가 3이상이라면
		for (int i = 0; i < word.length() - 1; i++) {
			int curr = word[i];
			int next = word[i + 1];
			check[curr - 'a'] = 1;

			if (curr == next) {
				continue;
			}
			else { // curr!=next인 경우
				if (check[next - 'a'] == 1) { //이미 나온 알파벳
					return false;
				}
				else { //처음나오는 알파벳
					continue;
				}
			}
		}
		return true;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (isGroupword(word) == true) { //그룹단어라면
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}