#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int p, n, r;
    string s;
    cin >> p;
    while (p--)
    {
        cin >> n >> r >> s;
        cout << n << " ";
        for (char c : s)
            fill_n(ostream_iterator<char>(cout), r, c);
        cout << '\n';
    }
}
