#include <iostream>
using namespace std;

int main()
{
    int h, w;
    while (cin >> h >> w)
    {
        string s;
        int z = 0;
        for (int i = 0; i < h; ++i)
        {
            cin >> s;
            bool in = false;
            for (size_t j = 0; j < w; ++j)
            {
                if (s[j] != '.')
                    z += 1, in = !in;
                else if (in)
                    z += 2;
            }
        }
        cout << z / 2 << '\n';
    }
}
