#include <bits/stdc++.h>
using namespace std;

void buildZ(int *Z, string str)
{
    int l = 0, r = 0;
    int n = str.length();
    Z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            // i does not lie between l and r 
            // z does not exist
            l = i;
            r = i;
            while (r < n && str[r] == str[r - l])
            {
                r++;
            }

            Z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (Z[k] <= r - i)
            {
                Z[i] = Z[k];
            }
            else
            {
                l = i;
                while (r < n && str[r] == str[r - l])
                {
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern)
{
    string str = pattern + '$' + text;
    int n = str.length();
    int *Z = new int[n];
    buildZ(Z, str);
    for (int i = 0; i < n; i++)
    {
        if (Z[i] == pattern.length())
        {
            cout << i - pattern.length() - 1 << endl;
        }
    }
}
int main()
{
    string text;
    string pattern;

    cin >> text >> pattern;
    searchString(text, pattern);
    return 0;
}
