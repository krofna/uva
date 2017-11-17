#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    string in;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << dec << "Case " << i + 1 << ':';
        cin >> in;
        unsigned char A[100] = {0}, ptr = 0;
        for (char c : in)
        {
            switch (c)
            {
                case '>': ptr = (ptr + 1) % 100; break;
                case '<': ptr = (ptr + 99) % 100; break;
                case '+': ++A[ptr]; break;
                case '-': --A[ptr]; break;
                case '.': break;
            }
        }
        for (int j = 0; j < 100; ++j)
        {
            cout << hex << uppercase << setfill('0') << setw(2) << (int)A[j];
            if (j != 99) cout << ' ';
        }
        cout << '\n';
    }
}
