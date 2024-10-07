#include <iostream>
#include <deque>

using namespace std;

// 그라운드가 모두 비어있지 않은지 확인하는 함수
bool notEmpty(const deque<int>& doGround, const deque<int>& suGround) {
    return !doGround.empty() && !suGround.empty();
}

// 게임 승자를 결정하는 함수
string whoWin(int n, int m, deque<int>& doCard, deque<int>& suCard) {
    deque<int> doGround, suGround;

    for (int turn = 0; turn < m; ++turn) {
        if (turn % 2 == 0) { // 도도의 차례
            doGround.push_back(doCard.back());
            doCard.pop_back();
        } else { // 수연의 차례
            suGround.push_back(suCard.back());
            suCard.pop_back();
        }

        // 덱이 비면 게임 종료
        if (doCard.empty()) return "su";
        if (suCard.empty()) return "do";

        // 수연이 종을 칠 조건: 두 그라운드의 카드 합이 5인 경우
        if (notEmpty(doGround, suGround) && (doGround.back() + suGround.back() == 5)) {
            // 도도의 그라운드를 수연의 덱으로 이동
            suCard.insert(suCard.begin(), doGround.rbegin(), doGround.rend());
            doGround.clear();
            // 수연의 그라운드를 수연의 덱으로 이동
            suCard.insert(suCard.begin(), suGround.rbegin(), suGround.rend());
            suGround.clear();
        }

        // 도도가 종을 칠 조건: 그라운드에 5가 나온 경우
        else if (!doGround.empty() && doGround.back() == 5 || !suGround.empty() && suGround.back() == 5) {
            // 수연의 그라운드를 도도의 덱으로 이동
            doCard.insert(doCard.begin(), suGround.rbegin(), suGround.rend());
            suGround.clear();
            // 도도의 그라운드를 도도의 덱으로 이동
            doCard.insert(doCard.begin(), doGround.rbegin(), doGround.rend());
            doGround.clear();
        }
    }

    // M번의 턴이 끝난 후 덱의 카드 수 비교
    if (doCard.size() == suCard.size()) return "dosu";
    return doCard.size() > suCard.size() ? "do" : "su";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> doCard(n), suCard(n);

    // 덱 입력 처리
    for (int i = 0; i < n; ++i) {
        cin >> doCard[i] >> suCard[i];
    }

    // 게임 결과 출력
    cout << whoWin(n, m, doCard, suCard) << '\n';

    return 0;
}