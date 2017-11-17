#include <iostream>
#include <algorithm>
using namespace std;

const string H[6] = { "HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE" };
const string L[7] = { "ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN", "UNKNOWN" };

int main()
{
    string in;
    int u = 1;
    while (cin >> in, in != "#")
        cout << "Case " << u++ << ": " << L[distance(H, find(H, H + 6, in))] << '\n';
}
