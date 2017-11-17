// TODO: bez struct nego s dva polja
#include <iostream>
#include <vector>
using namespace std;

int s, b, l, r;

struct soldier
{
    int l, r;
};

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s >> b, s || b)
    {
        vector<soldier> A;
        A.reserve(s);
        for (int i = 0; i < s; ++i)
            A.push_back({i - 1, i + 1});

        for (int i = 0; i < b; ++i)
        {
            cin >> l >> r; l--; r--;
            if (A[l].l != -1)
            {
                A[A[l].l].r = A[r].r;
                cout << A[l].l + 1 << ' ';
            }
            else
                cout << "* ";
            
            if (A[r].r != s)
            {
                A[A[r].r].l = A[l].l;
                cout << A[r].r + 1 << '\n';
            }
            else
                cout << "*\n";
        }
        cout << "-\n";
    }
}
