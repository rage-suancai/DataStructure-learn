#include <stdio.h>

void practice1(int n) {

    int size;
    scanf("%d", &size);

    int dp[size+1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= size; ++i) {
        dp[i] = 0;
        for (int j = 0; j < i; ++j) dp[i] += dp[j] * dp[i-j-1];
    }

    printf("%d", dp[size]);

}

int practice2(int n) {

    int res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;

}

int main() {

    //pracitce1();

    int n;
    scanf("%d", &n);
    printf("%d", practice2(2*n) / (practice2(n) * practice2(n+1)));

    return 0;

}

