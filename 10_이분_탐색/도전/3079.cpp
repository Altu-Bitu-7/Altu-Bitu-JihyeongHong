#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canProcessAll(const vector<int>& times, int m, long long mid) {
    long long totalPeople = 0;
    for (int time : times) {
        totalPeople += mid / time; 
        if (totalPeople >= m) return true; 
    }
    return totalPeople >= m;
}

long long findMinTime(int n, int m, vector<int>& times) {
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * static_cast<long long>(m);
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canProcessAll(times, m, mid)) {
            answer = mid; 
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    long long result = findMinTime(n, m, times);
    cout << result << endl;
    return 0;
}
