#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
    char la = tolower(a);
    char lb = tolower(b);
    if (la == lb)
        return a < b;
    return la < lb;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string in;
        cin >> in;
        sort(in.begin(), in.end(), cmp);
        do cout << in << '\n';
        while (next_permutation(in.begin(), in.end(), cmp));
    }
}
