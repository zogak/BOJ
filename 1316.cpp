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
	else { //�ܾ��� ���̰� 3�̻��̶��
		for (int i = 0; i < word.length() - 1; i++) {
			int curr = word[i];
			int next = word[i + 1];
			check[curr - 'a'] = 1;

			if (curr == next) {
				continue;
			}
			else { // curr!=next�� ���
				if (check[next - 'a'] == 1) { //�̹� ���� ���ĺ�
					return false;
				}
				else { //ó�������� ���ĺ�
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
		if (isGroupword(word) == true) { //�׷�ܾ���
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}