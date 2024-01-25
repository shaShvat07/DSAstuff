#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb(n) push_back(n)
#define f(i, n) for (int i = 0; i < n; i++)
#define ff(i, x, n) for (int i = x; i < n; i++)
#define all(s) (s).begin(), (s).end()
using namespace std;

string modify(string s)
{
    string newString = "#";
    for (char c : s)
    {
        newString += c;
        newString += "#";
    }
    return newString;
}

vi manacher(string s)
{
    int n = s.size();
    vi arr(n, 0);
    int center = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int other = 2 * center - i;
        if (i < r)
            arr[i] = min(arr[other], r - i);
        while (i + 1 + arr[i] < n && i - 1 - arr[i] >= 0 && s[i + 1 + arr[i]] == s[i - 1 - arr[i]])
            arr[i]++;
        if (i + arr[i] > r)
        {
            center = i;
            r = i + arr[i];
        }
    }
    return arr;
}

void solve()
{
    string text;
    cin >> text;
    string modifiedText = modify(text);
    vi arr = manacher(modifiedText);
    int ans = *max_element(arr.begin(), arr.end());
    cout << ans << endl;
    for(int v : arr){
        cout << arr[v] << " ";
    }
    cout << accumulate(arr.begin(), arr.end());
}

int main()
{
    solve();
    return 0;
}
