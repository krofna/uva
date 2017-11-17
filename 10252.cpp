#include <iostream>
using namespace std;

int main()
{
    string a, b;
    while (getline(cin, a), getline(cin, b), cin)
    {
        int M[26] = {}, N[26] = {};
        for (char c : a)
            M[c - 'a']++;
        for (char c : b)
            N[c - 'a']++;
        for (int i = 0; i < 26; ++i)
            cout << string(min(M[i], N[i]), i + 'a');
        cout << '\n';
    }
}
