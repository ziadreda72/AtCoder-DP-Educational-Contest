#include <bits/stdc++.h>

using namespace std;

const int N = 105 , MAX = (int) 1e5 + 10;

int n , W;
pair < int , int > a[N];
long long dp[N][MAX];

long long solve(int i , int w)
{
    if(i > n) return 0;
    long long &ret = dp[i][w];
    if(ret != -1) return ret;
    long long op1 = solve(i + 1 , w);
    long long op2 = -1;
    if(w - a[i].first >= 0) op2 = a[i].second + solve(i + 1 , w - a[i].first);
    return ret = max(op1 , op2);
}

// Top-Down Approach
void Top_Down(){
    memset(dp , -1 , sizeof dp);
    cout << solve(1 , W);
}

// Bottom-Up Approach
void Bottom_UP(){
    for (int i = 0; i <= W ; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j <= W ; ++j) {
            if(a[i].first > j){
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - a[i].first] + a[i].second);
        }
    }
    cout << dp[n][W];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    Bottom_UP();
    return 0;
}
