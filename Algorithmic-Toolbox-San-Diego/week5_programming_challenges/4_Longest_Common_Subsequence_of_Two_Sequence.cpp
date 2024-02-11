#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    int a_size=a.size();
    int b_size=b.size();
    vector<vector<int>>dp(a_size+1,vector<int>(b_size+1));
    for(int i=a_size-1;i>=0;i--){
        for(int j=b_size-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j]+=1+dp[i+1][j+1];
            }
            else{
                dp[i][j]=std::max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
