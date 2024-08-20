#include <iostream>
#include <cmath>

using namespace std;
// ���� ��緮 ��ȭ�� ���� ���̾�Ʈ
void simpleDiet(int d, int weight, int energy_diet, int metabol, int act) {
    for (int i = 0; i < d; i++) {
        // ü�� ���
        weight += energy_diet - (metabol + act);
        // ��� ��
        if (weight <= 0) {
            cout << "Danger Diet\n";
            return;
        }

    }
    // ��� ���
    cout << weight << " " << metabol << "\n";
}
// ���ʴ�緮 ��ȭ�� �ִ� ���̾�Ʈ
void diet(int metabol, int d, int weight, int energy_diet, int act, int t, int energy) {
    int metabol_diet = metabol;
    for (int i = 0; i < d; i++) {
        // ü�� ���
        weight += energy_diet - (metabol_diet + act);
        // ���ʴ�緮 ���
        if (abs(energy_diet - metabol_diet - act) > t) {
            metabol_diet += floor((energy_diet - metabol_diet - act) / 2.0);
        }
        //��� ��
        if (weight <= 0 || metabol_diet <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    // ��� ���
    cout << weight << " " << metabol_diet << " ";
    if (energy - metabol_diet > 0) {
        cout << "YOYO";
    }
    else {
        cout << "NO";
    }
}
int main() {
    // �Է�
    int weight, energy, metabol, t;
    int d, energy_diet, act;
    cin >> weight >> energy >> t;
    cin >> d >> energy_diet >> act;
    metabol = energy;
    // ���
    simpleDiet(d, weight, energy_diet, metabol, act);
    diet(metabol, d, weight, energy_diet, act, t, energy);

    return 0;
}