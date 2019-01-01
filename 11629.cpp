#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, g;
    cin >> p >> g;
    unordered_map<string, int> M;
    for (int i = 0; i < p; ++i)
    {
        string s, v;
        cin >> s >> v;
        v.erase(v.find('.'), 1);
        M[s] = stoi(v);
    }
    for (int i = 0; i < g; ++i)
    {
        string s, z;
        int sum = 0;
        do
        {
            cin >> s;
            sum += M[s];
        } while (cin >> s, s == "+");
        cin >> z;
        int c = stoi(z) * 10;
        bool f;
        if (s == "=")
            f = sum == c;
        else if (s == "<")
            f = sum < c;
        else if (s == ">")
            f = sum > c;
        else if (s == "<=")
            f = sum <= c;
        else
            f = sum >= c;
        cout << "Guess #" << i + 1 << " was ";
        cout << (f ? "correct" : "incorrect") << ".\n";
    }
}
