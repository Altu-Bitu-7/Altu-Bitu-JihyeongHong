// 2607: 비슷한 단어 (실버3/구현, 문자열)
#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26; // 총 알파벳 개수 최대 설정

/*
* 원본 단어와의 차이의 개수를 센다.
*/

/*
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

// 각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq) {
    for (int i = 0; i < word.length(); i++) { // 해당 단어의 길이만큼 반복문 돌면서
        freq[word[i] - 'A']++; // 알파벳 자리에 얼마나 알파벳이 단어에 나타난 횟수 기록
    }
}

int countDiff(string word, vector<int> original_freq) {
    vector<int> freq(NUM_CHARS, 0); // 알파벳이 얼마나 나타났는지 담을 벡터 만들기
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); // 각 알파벳의 개수 세기
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) { // 첫번째 단어의 알파벳 나온 횟수 기록한벡터를 돌면서
        diff += abs(original_freq[i] - freq[i]); // 첫번째 단어와 다른 개수만큼 기록
    }
    return diff;
}

int main() {
    int n, ans = 0; // 단어의 개수
    string original; // 첫번째 단어

    // 입력
    cin >> n >> original; // 단어의 개수와 첫번째 단어 입력
    vector<int> original_freq(NUM_CHARS, 0); // 알파벳 개수만은 vector 만들기

    // 연산
    countFreq(original, original_freq); // original_freq에 첫번째 단어에서 알파벳 나온 횟수 기록

    for (int i = 1; i < n; i++) { // n만큼 반복
        string word; // 비슷한지 안 비슷한지 확인하기 위해 단어 입력 받기
        cin >> word;

        int diff = countDiff(word, original_freq); // 첫번째 단어와 각 단어가 다른 개수 기록
        // 비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++; //첫번째 단어의 다른 개수가 1개 이하거나 2개인데 길이가 같은 경우에 비슷한 단어 수 증가
        }
    }
    
    // 출력
    cout << ans; // 비슷한 단어의 수 출력
    return 0;
}