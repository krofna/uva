#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, p, k;
    cin >> n;
    while (n--)
    {
        cin >> p;
        cin.ignore();
        vvi A(p);
        int mn = 1000;
        for (int i = 0; i < p; ++i)
        {
            string s;
            getline(cin, s);
            istringstream iss(s);
            while (iss >> k)
                A[i].push_back(k);

            mn = min<int>(A[i].size(), mn);
        }
        bool flg = false;
        for (int i = 0; i < p; ++i)
        {
            if (A[i].size() == mn)
            {
                if (flg) cout << ' ';
                cout << i + 1;
                flg = true;
            }
        }
        cout << '\n';
    }
}
