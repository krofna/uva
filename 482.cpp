#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int t, k;
    cin >> t;
    while (t--)
    {
        cin.ignore(2);
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<int> P;
        while (iss >> k)
            P.push_back(k - 1);

        vector<string> A(P.size());
        for (int i = 0; i < P.size(); ++i)
            cin >> A[P[i]];

        copy(A.begin(), A.end(), ostream_iterator<string>(cout, "\n"));
        if (t) cout << '\n';
    }
}
