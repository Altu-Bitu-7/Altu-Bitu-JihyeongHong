#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int left = 0, right = 0;
    vector<int> counter(*max_element(numbers.begin(), numbers.end()) + 1, 0);
    int answer = 0;

    while (right < N) {
        if (counter[numbers[right]] < K) {
            counter[numbers[right]]++;
            right++;
        } else {
            counter[numbers[left]]--;
            left++;
        }
        answer = max(answer, right - left);
    }

    cout << answer;

    return 0;
}
