#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;

int n;
int a[N][4];
int dp[N][3] , dp2[N][4];

int solve(int i , int lst){
    if(i >= n) return 0;
    int &ret = dp2[i][lst];
    if(~ret) return ret;
    int ans = 0;
    for (int j = 1; j <= 3 ; ++j) {
        if(lst != j){
            ans = max(ans , a[i][j] + solve(i + 1 , j));
        }
    }
    return ret = ans;
}

// Top-Down Approach
void Top_Down(){
    memset(dp2 , -1 , sizeof dp2);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> a[i][j];
        }
    }
    solve(0 , 0);
}

// Bottom-Up Approach
void Bottom_Up(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        dp[0][i] = a[0][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int mx = 0;
            for (int k = 0; k < 3; ++k) {
                if(j == k) continue;
                mx = max(mx , dp[i - 1][k]);
            }
            dp[i][j] = mx + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = max(ans , dp[n - 1][i]);
    }
    cout << ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
