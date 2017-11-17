#include <iostream>
#include <queue>
using namespace std;

typedef queue<int> qi;
typedef queue<qi*> qpqi;

int main()
{
    int t, k, T[1000000], x, q = 1;
    while (cin >> t, t)
    {
        cout << "Scenario #" << q++ << '\n';
        for (int i = 0; i < t; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
                cin >> x, T[x] = i;
        }
        qi U[1000];
        qpqi Q;
        string s;
        while (cin >> s, s != "STOP")
        {
            if (s == "ENQUEUE")
            {
                cin >> x;
                if (U[T[x]].empty())
                    Q.push(&U[T[x]]);
                U[T[x]].push(x);
            }
            else
            {
                cout << Q.front()->front() << '\n';
                Q.front()->pop();
                if (Q.front()->empty())
                    Q.pop();
            }
        }
        cout << '\n';
    }
}
