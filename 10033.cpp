#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    for (int k = 0; k < t; ++k)
    {
        if (k)
            cout << '\n';

        string in;
        int n = 0, R[10] = {}, RAM[1000] = {};
        while (getline(cin, in), !in.empty())
            RAM[n++] = stoi(in);

        n = 0;
        int ctr = 1;
        while (RAM[n] != 100)
        {
            int b = (RAM[n] / 10) % 10, c = RAM[n] % 10;
            switch (RAM[n] / 100)
            {
                case 2: R[b] = c; break;
                case 3: R[b] = (R[b] + c) % 1000; break;
                case 4: R[b] = (R[b] * c) % 1000; break;
                case 5: R[b] = R[c]; break;
                case 6: R[b] = (R[b] + R[c]) % 1000; break;
                case 7: R[b] = (R[b] * R[c]) % 1000; break;
                case 8: R[b] = RAM[R[c]]; break;
                case 9: RAM[R[c]] = R[b]; break;
                case 0: if (R[c]) n = R[b] - 1; break;
            }
            ctr += 1;
            n = (n + 1) % 1000;
        }
        cout << ctr << '\n';
    }
}
