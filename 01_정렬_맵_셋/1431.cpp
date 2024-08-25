#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//1431
bool cmp(const string& s1, const string& s2) {
    // ª���� �տ� �α�
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    // �ڸ� ���� ���� ���ϱ�
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (isdigit(s1[i])) {
            sum1 += s1[i] - '0';
        }


    }

    for (int i = 0; i < s2.size(); i++) {
        if (isdigit(s2[i])) {
            sum2 += s2[i] - '0';
        }

    }
    // ���� ������ �տ� �α�
    if (sum1 != sum2)
        return sum1 < sum2;
    // ������
    return s1 < s2;

}

int main() {
    // �Է�
    int n;
    cin >> n;
    vector<string> s_num;
    s_num.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> s_num[i];
    }
    // ����
    sort(s_num.begin(), s_num.end(), cmp);
    // ���
    for (int i = 0; i < n; i++) {
        cout << s_num[i] << "\n";
    }
    return 0;
}