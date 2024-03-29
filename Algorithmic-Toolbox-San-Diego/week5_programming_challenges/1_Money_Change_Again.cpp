#include <iostream>
using namespace std;

int get_change(int m) {
    int dp[m+1];
    int default_value=m+1;
    fill(dp,dp+m+1,default_value);
    int coins[3]={1,3,4};
    dp[0]=0;
    for(int i=1;i<=m+1;i++){
        for(int j=0;j<3;j++){
            if(i-coins[j]>=0){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[m]!=m+1)
        return dp[m];


}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
