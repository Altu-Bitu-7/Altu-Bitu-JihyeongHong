#include <iostream>
#include <cmath>

using namespace std;
// 기초 대사량 변화가 없는 다이어트
void simpleDiet(int d, int weight, int energy_diet, int metabol, int act) {
    for (int i = 0; i < d; i++) {
        // 체중 계산
        weight += energy_diet - (metabol + act);
        // 사망 시
        if (weight <= 0) {
            cout << "Danger Diet\n";
            return;
        }

    }
    // 결과 출력
    cout << weight << " " << metabol << "\n";
}
// 기초대사량 변화가 있는 다이어트
void diet(int metabol, int d, int weight, int energy_diet, int act, int t, int energy) {
    int metabol_diet = metabol;
    for (int i = 0; i < d; i++) {
        // 체중 계산
        weight += energy_diet - (metabol_diet + act);
        // 기초대사량 계산
        if (abs(energy_diet - metabol_diet - act) > t) {
            metabol_diet += floor((energy_diet - metabol_diet - act) / 2.0);
        }
        //사망 시
        if (weight <= 0 || metabol_diet <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    // 결과 출력
    cout << weight << " " << metabol_diet << " ";
    if (energy - metabol_diet > 0) {
        cout << "YOYO";
    }
    else {
        cout << "NO";
    }
}
int main() {
    // 입력
    int weight, energy, metabol, t;
    int d, energy_diet, act;
    cin >> weight >> energy >> t;
    cin >> d >> energy_diet >> act;
    metabol = energy;
    // 출력
    simpleDiet(d, weight, energy_diet, metabol, act);
    diet(metabol, d, weight, energy_diet, act, t, energy);

    return 0;
}