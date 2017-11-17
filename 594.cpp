#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    int32_t n;
    while (cin >> n)
        cout << n << " converts to " << (int)__builtin_bswap32(n) << '\n';
}
