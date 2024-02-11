#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> min_operations(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    vector<int> ans;
    ans.push_back(n);
    while (n != 1) {
        if (n % 3 == 0 && dp[n] - 1 == dp[n / 3]) {
            n /= 3;
            ans.push_back(n);
        } else if (n % 2 == 0 && dp[n] - 1 == dp[n / 2]) {
            n /= 2;
            ans.push_back(n);
        } else {
            n -= 1;
            ans.push_back(n);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {
    int n;
    cin >> n;
    vector<int> ans = min_operations(n);
    std::cout << ans.size() - 1 << std::endl;
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
}