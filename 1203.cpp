#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef priority_queue<iii, viii, greater<iii> > pq;

int main()
{
    string s;
    int id, fq, fq2, n = 0, k;
    pq Q;
    while (cin >> s, s != "#")
    {
        cin >> id >> fq, n++;
        Q.emplace(fq, id, fq);
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        tie(fq2, id, fq) = Q.top(); Q.pop();
        cout << id << '\n';
        Q.emplace(fq2 + fq, id, fq);
    }
}
