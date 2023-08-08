#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, t;
        cin >> n >> t;
        int tm[n], ent[n];
        for (int i = 0; i < n; i++)
            cin >> tm[i];
        for (int i = 0; i < n; i++)
            cin >> ent[i];
        int ind = -1;
        int maxi = -1e9;
        for (int i = 0; i < n; i++)
        {
            if (tm[i] <= t && ent[i] > maxi)
            {
                ind = i;
                maxi = ent[i];
            }
            t--;
        }
        if (ind != -1)
            cout << ind + 1 << '\n';
        else
            cout << ind << endl;
    }

    return 0;
}