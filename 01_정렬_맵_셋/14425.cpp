#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// �Է�
	int n, m;
	int sum = 0;
	cin >> n >> m;
	string str;
	string input;
	set<string> s;
	// ���ڿ� �Է�
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}
	// ���ڿ� �ִ��� Ȯ��
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.find(input) != s.end()) {
			sum++;
		}
	}
	// ���
	cout << sum;

	return 0;
}