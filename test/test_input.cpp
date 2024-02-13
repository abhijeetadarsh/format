#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bird/bug.h>
#endif

using namespace std;

#define int            long long
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define max_heap       priority_queue <int>
#define min_heap       priority_queue <int, vi, greater<int>>
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define MOD            1000000007

const int maxm = 2e5;
int dp[10][maxm + 1];

inline int power(int a, int b)
{
    int x = 1;
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
    int n, m;
public:
    void bird() {
        cin >> n >> m;

        int ans = 0;
        while(n) {
            ans += dp[n % 10][m];
            n /= 10;
        }

        cout << ans << endl;
    }
};


int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    for(int j = 0; j <= maxm; j++) {
        for(int i = 0; i < 10; i++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i == 9) {
                dp[i][j] = (dp[1][j-1] + dp[0][j-1]) % MOD;
                continue;
            }
            dp[i][j] = dp[i+1][j-1];
        }
    }

    Sol sss;
    int t = 1;
    cin >> t;
    while (t--) sss.bird();
}

/* Author : Abhijeet Adarsh */