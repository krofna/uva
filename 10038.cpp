#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, k, l;
    while (cin >> n)
    {
        bool B[3000] = {}, jolly = true;
        cin >> k;
        for (int i = 1; i < n; ++i)
        {
            cin >> l;
            int x = abs(k - l);
            if (x < 1 || x >= n || B[x])
                jolly = false;
            B[x] = true;
            k = l;
        }
        cout << (jolly ? "Jolly\n" : "Not jolly\n");
    }
}
