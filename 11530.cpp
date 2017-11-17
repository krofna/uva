#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int k = 0; k < t; ++k)
    {
        string in;
        getline(cin, in);
        int sum = 0;
        for (int i = 0; i < in.size(); ++i)
        {
            if (in[i] == ' ')
                sum += 1;
            else if (in[i] < 'p')
                sum += (in[i] - 'a') % 3 + 1;
            else if (in[i] < 't')
                sum += (in[i] - 'p') % 4 + 1;
            else if (in[i] < 'w')
                sum += (in[i] - 't') % 3 + 1;
            else
                sum += (in[i] - 'w') % 4 + 1;
        }
        cout << "Case #" << k + 1 << ": " << sum << '\n';
    }
}
