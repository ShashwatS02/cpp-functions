#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvi = vector<vll>;

#define pb push_back
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, n) for (ll i = 0; i < (n); ++i)
#define loop2(i, a, b) for (ll i = (a); i < (b); ++i)
#define print(x) cout << (x) << "\n"
#define yes print("Yes")
#define no print("No")

const ll MOD = 1e9 + 7;
const ll INF = 2e18;
const ll N = 1e5 + 10;

bool check(ll day, vll &pref, ll need, ll total_days, ll n) {
    ll cycles = total_days / (day + 1);
    ll rem = total_days % (day + 1);
    ll sum = cycles * pref[min(day + 1, n)];
    sum += pref[min(rem, n)];
    return sum >= need;
}

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    vll a(n);
    for (auto &x : a) cin >> x;
    sort(all(a), greater<ll>());
    vll pref(n + 1, 0);
    loop(i, n) pref[i + 1] = pref[i] + a[i];
    if (a[0] * d < c) {
        print("Impossible");
        return;
    }
    if (pref[min(d, n)] >= c) {
        print("Infinity");
        return;
    }
    ll lo = 0, hi = d, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid, pref, c, d, n)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
