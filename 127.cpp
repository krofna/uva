#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<stack<string> > A;

bool ok(string a, string b)
{
    return a[1] == b[1] || a[0] == b[0];
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin.peek() != '#')
    {
        A.clear();
        for (int i = 0; i < 52; ++i)
        {
            string s;
            cin >> s;
            stack<string> ss;
            ss.push(s);
            A.push_back(ss);
        }
        while (true)
        {
            int i;
            for (i = 1; i < A.size(); ++i)
            {
                if (i >= 3 && ok(A[i].top(), A[i - 3].top()))
                {
                    A[i - 3].push(A[i].top());
                    A[i].pop();
                    break;
                }
                if (ok(A[i].top(), A[i - 1].top()))
                {
                    A[i - 1].push(A[i].top());
                    A[i].pop();
                    break;
                }
            }
            if (i == A.size())
                break;
            if (A[i].empty())
                A.erase(A.begin() + i);
        }
        cout << A.size() << (A.size() == 1 ? " pile" : " piles") << " remaining:";
        for (int i = 0; i < A.size(); ++i)
            cout << " " << A[i].size();
        cout << '\n';
        cin.ignore();
    }
}
