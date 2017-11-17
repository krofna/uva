#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct con
{
    int s, p, P[9], id;
    bool A[9], flg;
    con() : s(0), p(0), P(), id(0), A(), flg(false) {}

    void sub(int pr, int j, char l)
    {
        flg = true;
        switch (l)
        {
        case 'I':
            P[pr - 1] += 20;
            break;
        case 'C':
            if (!A[pr - 1])
            {
                A[pr - 1] = true;
                p += j + P[pr - 1];
                s++;
            }
            break;
        }
    }

    bool operator<(const con& o) const
    {
        if (s != o.s)
            return s > o.s;
        if (p != o.p)
            return p < o.p;
        return flg > o.flg;
    }
};

int main()
{
    int t, c, p, j;
    char l;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        string s;
        con C[100];
        while (getline(cin, s), !s.empty())
        {
            istringstream iss(s);
            iss >> c >> p >> j >> l;
            C[c - 1].id = c;
            C[c - 1].sub(p, j, l);
        }
        stable_sort(C, C + 100);
        for (int i = 0; i < 100 && C[i].id; ++i)
            cout << C[i].id << ' ' << C[i].s << ' ' << C[i].p << '\n';
        if (t) cout << '\n';
    }
}
