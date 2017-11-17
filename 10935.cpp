#include <iostream>
#include <deque>
#include <numeric>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        deque<int> Q(n);
        iota(Q.begin(), Q.end(), 1);
        cout << "Discarded cards:";
        while (Q.size() != 1)
        {
            cout << " " << Q.front();
            Q.pop_front();
            Q.push_back(Q.front());
            Q.pop_front();
            if (Q.size() != 1) cout << ",";
        }
        cout << "\nRemaining card: " << Q.front() << '\n';
    }
}
