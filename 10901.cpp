#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int c, n, t, m, k, tm;
queue<pair<int, int> > *Q, *T;
int A[10000];

void Travel()
{
    tm += t;
    swap(Q, T);
}

void DoBank()
{
    int k = 0;
    while (!Q->empty() && Q->front().first <= tm && k < n)
    {
        A[Q->front().second] = tm + t;
        Q->pop();
        ++k;
    }
    if (!k)
    {
        if (Q->empty())
        {
            tm = max(tm, T->front().first);
            Travel();
        }
        else if (T->empty())
        {
            tm = max(tm, Q->front().first);
        }
        else
        {
            if (T->front().first < Q->front().first)
            {
                tm = max(tm, T->front().first);
                Travel();
            }
            else
                tm = max(tm, Q->front().first);
        }
    }
    else
        Travel();
}

int main()
{
    cin >> c;
    while (c--)
    {
        cin >> n >> t >> m;
        queue<pair<int, int> > L, R;
        for (int i = 0; i < m; ++i)
        {
            string s;            
            cin >> k >> s;
            if (s[0] == 'l')
                L.emplace(k, i);
            else
                R.emplace(k, i);
        }
        tm = 0;
        Q = &L; T = &R;
        while (!(R.empty() && L.empty()))
            DoBank();
        for (int i = 0; i < m; ++i)
            cout << A[i] << '\n';
        if (c) cout << '\n';
    }
}
