#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, string> is;
typedef vector<is> vis;

int main()
{
    int n;
    while (cin >> n)
    {
        vis v;
        for (int i = 0; i < n; ++i)
        {
            string a, b;
            cin >> a >> b;
            if (isdigit(a[0]))
                v.emplace_back(stoi(a), b);
            else v.emplace_back(stoi(b) * 2, a);
        }
        sort(v.begin(), v.end());
        for (is& p : v)
            cout << p.second << '\n';
    }
}
