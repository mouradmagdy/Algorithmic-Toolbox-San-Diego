#include<iostream>
#include<vector>
using namespace std;
int compute_min(int w,int n,vector<int>&weights) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
            }
        }
    }
    return dp[n][w];
}

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> weights(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        weights[i] = x;
    }
    cout << compute_min(w, n, weights);
}