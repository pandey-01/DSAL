#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define endl '\n'

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Fast input/output
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Utility functions
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Debugging utility
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// Main function
int main() {
    fastIO();

    // Example usage
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        
    }

    return 0;
}
