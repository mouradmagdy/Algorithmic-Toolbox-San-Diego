#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n,sum = 0;
int weights[21];
bool dp[21][601][601];

int main() {
    cin >> n;
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
        sum += weights[i];
        dp[i][0][0] = true;
    }
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (weights[i] <= j && dp[i - 1][j - weights[i]][k]) {
                    dp[i][j][k] = true;
                }
                if (weights[i] <= k && dp[i - 1][j][k - weights[i]]) {
                    dp[i][j][k] = true;
                }
            }
        }
    }
    if (dp[n][sum / 3][sum / 3]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

}