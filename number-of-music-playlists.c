#include <stdio.h>

#define MOD 1000000007

int numMusicPlaylists(int n, int goal, int k) {
    long long dp[101][101] = {0};
    dp[0][0] = 1;
    for (int i = 1; i <= goal; i++)
        for (int ii = 1; ii <= n; ii++) {
            dp[i][ii] += dp[i-1][ii-1] * (n - (ii - 1));
            dp[i][ii] %= MOD;
            if (ii > k) {
                dp[i][ii] += dp[i - 1][ii] * (ii - k);
				dp[i][ii] %= MOD;
			}
        }
    return dp[goal][n];
}
