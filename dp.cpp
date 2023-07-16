#include <bits/stdc++.h>
#include <string>
using namespace std;

int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
        output[i] = new int[n + 1];

    // Fill first row !
    for (int j = 0; j <= n; j++)
        output[0][j] = 0;

    // Fill first column
    for (int i = 1; i <= m; i++)
        output[i][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Check if first character matches
            if (s[m - i] == t[n - j])
                output[i][j] = 1 + output[i - 1][j - 1];

            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = max(a, max(b, c));
            }
        }
    }

    return output[m][n];
}
int lcs(string s, string t)
{
    // Base Call
    if (s.size() == 0 || t.size() == 0)
        return 0;
    // Recursive Call
    if (s[0] == t[0])
        return 1 + lcs(s.substr(1), t.substr(1));

    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    return 0;
}