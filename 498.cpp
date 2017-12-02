#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> A;

int f(int x, int i)
{
    return i >= 0 ? A[i] + x * f(x, i - 1) : 0;
}

int main()
{
    ios::sync_with_stdio(false);
    string a, b;
    while (getline(cin, a), getline(cin, b), cin)
    {
        int k;
        bool q = false;
        A.clear();
        istringstream iss(a);
        while (iss >> k) A.push_back(k);
        istringstream izz(b);
        while (izz >> k)
        {
            if (q)
                cout << ' ';
            q = true;
            cout << f(k, A.size() - 1);
        }
        cout << '\n';
    }
}
