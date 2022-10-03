#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;

int n;
int h[N];
int dp[N];

int solve(int i){
    if(i > n) return (int) 1e6;
    if(i == n) return 0;
    int &ret = dp[i];
    if(~ret) return ret;
    return ret = min(solve(i + 1) + abs(h[i] - h[i + 1]) , solve(i + 2) + abs(h[i] - h[i + 2]));
}

// Top-Down Approach
void Top_Down(){
    memset(dp , -1 , sizeof dp);
    cout << solve(1);
}

// Bottom-Up Approach
void Bottom_UP(){
    dp[1] = 0;
    dp[2] = dp[1] + abs(h[1] - h[2]);
    for (int i = 3; i <= n ; ++i) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]) , dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n ; ++i) {
        cin >> h[i];
    }
    Top_Down();
    return 0;
}
