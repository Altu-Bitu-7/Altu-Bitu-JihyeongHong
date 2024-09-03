#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>  

using namespace std;


void isPrime(int n, vector<bool> &is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void findGoldbachConjecture(int n, const vector<bool> &isP) {
    int a = 3;
    int b = n - a;

   while (a <= n / 2) {
        if (isP[a] && isP[b]) {
            printf("%d = %d + %d\n", n, a, b);
            return;
        }
        a += 2;
        b -= 2;
    }
    printf("Goldbach's conjecture is wrong.\n");
}

int main() {
    int max_n = 1000000;
    vector<bool> isP(max_n + 1, true);

   isPrime(max_n, isP);

    vector<int> queries;
    int n;
  while (scanf("%d", &n) && n != 0) {
        queries.push_back(n);
    }
 for (int num : queries) {
        findGoldbachConjecture(num, isP);
    }

    return 0;
}