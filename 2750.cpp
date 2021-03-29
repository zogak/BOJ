/*sort*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num;
vector <int> vec;
int main() {
	cin >> n;
	while (n--) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}