#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 입력
	int n, m;
	int sum = 0;
	cin >> n >> m;
	string str;
	string input;
	set<string> s;
	// 문자열 입력
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}
	// 문자열 있는지 확인
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.find(input) != s.end()) {
			sum++;
		}
	}
	// 출력
	cout << sum;

	return 0;
}