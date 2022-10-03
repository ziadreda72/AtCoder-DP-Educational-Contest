#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;

int n , k;
int h[N];
int dp[N];

int solve(int i){
    if(i == n) return 0;
    int &ret = dp[i];
    if(~ret) return ret;
    int mn = INT_MAX;
    for (int j = 1; j <= k ; ++j) {
        if(i + j > n) break;
        mn = min(mn , solve(i + j) + abs(h[i] - h[i + j]));
    }
    return ret = mn;
}

// Top-Down Approach
void Top_Down(){
    memset(dp , -1 , sizeof dp);
    cout << solve(1);
}

// Bottom-Up Approach
void Bottom_UP(){
    for (int i = 1; i <= n ; ++i) {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    for (int i = 2; i <= n ; ++i) {
        for (int j = 1; j <= k ; ++j) {
            if(i - j <= 0) break;
            dp[i] = min(dp[i] , dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n ; ++i) {
        cin >> h[i];
    }
    Bottom_UP();
    return 0;
}
