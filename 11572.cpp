#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> M;
        int mx = 0, curr = 0, left = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            auto it = M.find(k);
            if (it != M.end())
            {

                left = max(left, it->second);
                curr = i - left;
            }
            else
                curr++;
            M[k] = i;
            mx = max(mx, curr);
        }
        cout << mx << '\n';
    }
}
