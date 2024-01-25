#include <bits/stdc++.h>
using namespace std;
#define for0(i, n) for (int i = 0; i < n; i++)
#define fork(i, k, n) for (int i = k; k <= n ? i <= n : i >= n; k <= n ? i++ : i--)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define gx(x) cout << #x << "=" << x << endl
#define gxy(x, y) cout << #x << "=" << x << "." << #y << "=" << y << endl
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))
#define tr(x, a) for (auto &x : a)
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef set<int> si;

/*-------------------------------------------------- UTILITIES-----------------------------------------------------------------------*/
const int N = (int)(2e5 + 5);
const int MOD = 1e18 + 5;
int fact[N], pow2[N], factinv[N];
#define PI 3.1415926535897932384626433832795
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool isprime(int N)
{
    if (N == 1)
        return 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (!(N % i))
            return 0;
    }
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
int ceil(int a, int b)
{
    int res = a / b;
    if (a % b)
        res++;
    return res;
}
int mod_add(int a, int b)
{
    int help = (a + b) % MOD;
    if (help < 0)
        help += MOD;
    return help;
}
int mod_sub(int a, int b)
{
    int help = (a - b) % MOD;
    if (help < 0)
        help += MOD;
    return help;
}
int mod_mul(int a, int b)
{
    int help = (a * b) % MOD;
    if (help < 0)
        help += MOD;
    return help;
}
int mpow(int a, int b)
{
    if (b == 0)
        return 1;
    int help = mpow(a, b / 2);
    help = mod_mul(help, help);
    if (b % 2)
        help = mod_mul(help, a);
    return help;
}
int mod_inv(int a) { return mpow(a, MOD - 2); }
int mod_div(int a, int b) { return mod_mul(a, mod_inv(b)); }
void init()
{
    fact[0] = 1;
    pow2[0] = 1;
    for1(i, N - 1)
    {
        fact[i] = mod_mul(i, fact[i - 1]);
        pow2[i] = mod_mul(2, pow2[i - 1]);
    }
    factinv[N - 1] = mod_inv(fact[N - 1]);
    fork(i, N - 2, 0) { factinv[i] = mod_mul(i + 1, factinv[i + 1]); }
}
int nCr(int n, int r)
{
    int help = mod_mul(fact[n], factinv[r]);
    help = mod_mul(help, factinv[n - r]);
    return help;
}
template <typename T>
void zero_based(vector<T> &v)
{
    fork(i, 1, v.size() - 1) v[i - 1] = v[i];
    v.pop_back();
}
template <typename T>
void one_based(vector<T> &v)
{
    int n = v.size();
    v.pb(v[n - 1]);
    fork(i, n, 1) v[i] = v[i - 1];
}
void helpwer(bool ok)
{
    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*----------------------------------------------------CODE BEGINS---------------------------------------------------------------------*/
bool distinct(int n)
{
    vi num(10, 0);
    while (n > 0)
    {
        num[n % 10]++;
        n /= 10;
    }
    for0(i, 10) if (num[i] > 1) return false;
    return true;
}
void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    vi aa, bb, ab, ba;
    if(s[0] == 'A'  && t[0] == 'B'){
        cout << -1 << endl;
        return;
    }
    if(s[n-1] == 'B' && t[n-1] == 'A'){
        cout << -1 << endl;
        return;
    }
    for0(i, n)
    {
        if (s[i] == t[i] && s[i] == 'A')
            aa.pb(i);
        else if (s[i] == t[i] && s[i] == 'B')
            bb.pb(i);
        else if (s[i] == 'A' && t[i] == 'B')
            ab.pb(i);
        else if (s[i] == 'B' && t[i] == 'A')
            ba.pb(i);
        else
            continue;
    }
    int ans = 0;
    int j = 0, i = 0;
    vector<bool> visiAB(ab.size(), false);
    vector<bool> visiBA(ba.size(), false);
    while (i < ba.size() && j < ab.size())
    {
        if (ba[i] < ab[j])
        {
            aa.pb(ba[i]);
            bb.pb(ab[j]);
            ans++;
            visiAB[j] = true; // Corrected index here
            visiBA[i] = true; // Corrected index here
            i++;   
            j++;           // Increment i in this case
        }
        else
        {
            j++;
        }
    }
    if (aa.size() + bb.size() == n)
    {
        cout << ans << endl;
        return;
    }
    if (aa.size() + bb.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    if(aa.size())
    {
        sort(aa.begin(), aa.end());
        for (int i = 0; i < ab.size(); i++)
        {
            if(visiAB[i] == true) continue;
            else if (aa[0] < ab[i] && visiAB[i] == false)
            {
                ans++;
                visiAB[i] = true;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    if(bb.size())
    {
        sort(bb.begin(), bb.end());
        for (int i = 0; i < ba.size(); i++)
        {
            if(visiBA[i] == true) continue;
            else if (ba[i] < bb[bb.size() - 1] && visiBA[i] == false)
            {
                ans++;
                visiBA[i] = true;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for0(i,visiAB.size()){
        if(visiAB[i] == false)
        {
            cout << -1 << endl;
            return;
        }
    }
    for0(i,visiBA.size()){
        if(visiBA[i] == false)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    cout << ans << endl; 
}
int32_t main()
{
    fastio();
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "#" << t << endl;
        solve();
        // cout << endl;
    }
    return 0;
}
