#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int dp[n][n];
    for(int l = 2; l < n; l++){
        for(int i = 0; i < n - l; i++){
            int j = i + l;
            dp[i][j] = 1e9;
            for(int k = i+1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i]*a[k]*a[j]);
        }
    }
    cout << dp[0][n-1] << "\n";
}
