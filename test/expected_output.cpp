/*
** Author : Abhijeet Adarsh
** Question : C_Add_One.cpp
** Date : 2023-09-10
** Time : 03:47:49
 ,_,        ,_,
(.,.)      (O,O)
(   )      (   )
-"-"---dwb--"-"---dwb-
*/
#include <bits/stdc++.h>
using namespace std;
const long long maxm = 2e5;
long long dp[10][maxm + 1];
inline long long power(long long a, long long b)
{
    long long x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
class Sol {
private:
    long long n, m;
public:
    void bird() {
        cin >> n >> m;
        long long ans = 0;
        while(n) {
            ans += dp[n % 10][m];
            n /= 10;
        }
        cout << ans << "\n";
    }
};
int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(long long j = 0; j <= maxm; j++) {
        for(long long i = 0; i < 10; i++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i == 9) {
                dp[i][j] = (dp[1][j-1] + dp[0][j-1]) % 1000000007;
                continue;
            }
            dp[i][j] = dp[i+1][j-1];
        }
    }
    Sol sss;
    long long t = 1;
    cin >> t;
    while (t--) sss.bird();
}
