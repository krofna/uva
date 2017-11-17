#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n, op, x;
    while (cin >> n)
    {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;
        bool s = true, q = true, pq = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> op >> x;
            if (op == 1)
            {
                S.push(x);
                Q.push(x);
                PQ.push(x);
            }
            else
            {
                if (S.empty() || S.top() != x)
                    s = false;
                if (Q.empty() || Q.front() != x)
                    q = false;
                if (PQ.empty() || PQ.top() != x)
                    pq = false;
                if (!S.empty())
                    S.pop();
                if (!Q.empty())
                    Q.pop();
                if (!PQ.empty())
                    PQ.pop();
            }
        }
        if (s && !q && !pq)
            cout << "stack\n";
        else if (q && !s && !pq)
            cout << "queue\n";
        else if (pq && !s && !q)
            cout << "priority queue\n";
        else if (s || q || pq)
            cout << "not sure\n";
        else
            cout << "impossible\n";
    }
}
