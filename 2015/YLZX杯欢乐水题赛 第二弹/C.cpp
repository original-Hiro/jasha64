#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

const int MAX_M = 7;
int dp[MAX_M][2200];

int main() {
	string stra, strb;
	cin >> stra >> strb;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= stra.size(); ++i) {
		for (int j = 0; j <= strb.size(); ++j) {
			if (i < 3) {
				dp[i][j] = 0;
			} else if (j < 3) {
				dp[i % MAX_M][j] = 0;
			} else {
				dp[i % MAX_M][j] = dp[(i - 1 + MAX_M) % MAX_M][j];
				dp[i % MAX_M][j] = max(dp[i % MAX_M][j], dp[i % MAX_M][j - 1]); 
				dp[i % MAX_M][j] = max(dp[i % MAX_M][j], dp[(i - 1 + MAX_M) % MAX_M][j - 1]); 
				for (int k = 1; k <= 6 && i - k >= 0 && j - k >= 0; ++k) {
					if (stra[i - k] != strb[j - k]) {
						break;
					}
					if (k >= 3) {
						dp[i % MAX_M][j] = 
							max(dp[i % MAX_M][j], dp[(i - k + MAX_M) % MAX_M][j - k] + k); 
					} 
				} 
			}
		}
	}
	cout <<  dp[stra.size() % MAX_M][strb.size()] << endl;
}
