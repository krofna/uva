#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int t = 1;
    while (getline(cin, s), s != "end")
    {
        string A(1000, 'Z' + 1);
        for (char c : s)
            *find_if(A.begin(), A.end(), [&](char l){return l >= c;}) = c;
        cout << "Case " << t++ << ": " << A.find('Z' + 1) << '\n';
    }
}
