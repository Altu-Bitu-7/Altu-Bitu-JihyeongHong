#include <iostream>

using namespace std;

int board[19][19];
const int MAX = 19;
pair<int, int> ans = {-1, -1};

// 4방향 (오른쪽, 아래, 오른쪽 아래 대각선, 왼쪽 아래 대각선)
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

// 주어진 좌표에서 해당 방향으로 연속된 바둑알의 개수를 셈
bool check_winner(int x, int y) {
    int stone = board[x][y];  // 현재 돌 (1: 검은 돌, 2: 흰 돌)
    
    // 4방향을 모두 검사
    for (int d = 0; d < 4; d++) {
        int cnt = 1;  // 현재 돌 포함해서 세므로 초기값은 1
        int nx = x + dx[d];
        int ny = y + dy[d];

        // 해당 방향으로 연속된 돌을 셈
        while (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && board[nx][ny] == stone) {
            cnt++;
            nx += dx[d];
            ny += dy[d];
        }

        // 반대 방향으로도 확인
        int prev_x = x - dx[d];
        int prev_y = y - dy[d];

        while (prev_x >= 0 && prev_x < MAX && prev_y >= 0 && prev_y < MAX && board[prev_x][prev_y] == stone) {
            cnt++;
            prev_x -= dx[d];
            prev_y -= dy[d];
        }

        // 돌이 5개 연속이고 6개가 아닌 경우
        if (cnt == 5) {
            // 이긴 돌의 위치는 가장 왼쪽/위쪽 돌을 출력해야 하므로 반대 방향 체크
            if (x - dx[d] < 0 || x - dx[d] >= MAX || y - dy[d] < 0 || y - dy[d] >= MAX || board[x - dx[d]][y - dy[d]] != stone) {
                ans = {x + 1, y + 1};  // 1-based 좌표 저장
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 바둑판 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
        }
    }

    // 바둑판을 순차적으로 탐색
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j] != 0) {  // 돌이 있는 자리에서만 확인
                if (check_winner(i, j)) {
                    cout << board[i][j] << "\n";  // 승리한 돌 색 출력
                    cout << ans.first << " " << ans.second << "\n";  // 승리한 위치 출력
                    return 0;
                }
            }
        }
    }

    // 승부가 나지 않았을 경우
    cout << "0\n";
    return 0;
}
