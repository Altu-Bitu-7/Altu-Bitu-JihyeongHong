#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxSushi(int N, int k, int c, const vector<int>& sushi, int d) {
    vector<int> chk(d + 1, 0);  
    chk[c] = 3001;  

    int cnt = 1;  

    
    for (int i = 0; i < k; i++) {
        if (chk[sushi[i]] == 0)
            cnt++;

        chk[sushi[i]]++;
    }

    int maxSushi = cnt;

    
    for (int i = 0; i < N; i++) {
        int sIdx = sushi[i];    
        int eIdx = sushi[(i + k) % N];    

        
        if (--chk[sIdx] == 0)
            cnt--;

        
        if (++chk[eIdx] == 1)
            cnt++;

        maxSushi = max(maxSushi, cnt);
    }

    return maxSushi;
}

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> sushi(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

   
    int result = getMaxSushi(N, k, c, sushi, d);

    cout << result << endl;

    return 0;
}
