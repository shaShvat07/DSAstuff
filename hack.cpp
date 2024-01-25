#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long M = 1e9 + 7;
long long mod(long long N)
{
    return (N % M + M) % M;
}

long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}

long long sub(long long a, long long b)
{
    return mod(mod(a) - mod(b) + M);
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;
    int tn = text.size();
    int pn = pattern.size();

    long long p = 31;

    // power mod M
    vector<long long> powMod(tn);
    powMod[0] = 1;
    for (int i = 1; i < tn; i++)
    {
        powMod[i] = mul(powMod[i - 1], p);
    }

    // calculating hash for pattern
    long long ph = 0;
    for (int i = 0; i < pn; i++)
        ph = add(ph, mul(pattern[i] - 'a' + 1, powMod[i]));

    // calculating prefix Hash for the text
    vector<long long> th(tn + 1);
    for (int i = 0; i < tn; i++)
    {
        th[i + 1] = add(th[i], mul(text[i] - 'a' + 1, powMod[i]));
    }

    // matching the text hash and pattern hash
    for (int i = 0; i < tn - pn + 1; i++)
    {
        long long hashVal = sub(th[i + pn], th[i]);
        if (hashVal == mul(ph, powMod[i]))
        {
            cout << "Fount at index " << i << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}
