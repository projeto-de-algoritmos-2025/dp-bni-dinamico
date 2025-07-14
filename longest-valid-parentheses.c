#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

int longestValidParentheses(char* s) {
	int max = 0, n = strlen(s), *dp = (int*)calloc(n, sizeof(int));
	for (int i = 1; i < n; i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') dp[i] = (i >= 2) ? dp[i - 2] + 2 : 2;
			else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
				dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
			max = MAX(max, dp[i]);
		}
	}
	//free(dp);
	return max;
}
