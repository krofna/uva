#include <iostream>
#include <tuple>
#include <cmath>
#include <unordered_map>
#include <iomanip>
using namespace std;

unordered_map<string, pair<double, double> > M =
{
    {"N", {0, 1} }, {"S", {0, -1} },
    {"E", {1, 0} }, {"W", {-1, 0} },
    {"SE", {sqrt(2) / 2, -sqrt(2) / 2} },
    {"SW", {-sqrt(2) / 2, -sqrt(2) / 2} },
    {"NE", {sqrt(2) / 2, sqrt(2) / 2} },
    {"NW", {-sqrt(2) / 2, sqrt(2) / 2} }
};

int main()
{
    string s;
    cout << fixed << setprecision(3);
    int t = 1;
    while (getline(cin, s), s != "END")
    {
        double x = 0, y = 0, dx, dy;
        for (int i = 0; i < s.size(); ++i)
        {
            string a, b;
            while (isdigit(s[i])) a += s[i++];
            while (isalpha(s[i])) b += s[i++];
            int n = stoi(a);
            tie(dx, dy) = M[b];
            x += n * dx; y += n * dy;
        }
        cout << "Map #" << t++ << "\n";
        cout << "The treasure is located at (" << x << "," << y << ").\n";
        cout << "The distance to the treasure is " << hypot(x,  y) << ".\n\n";
    }
}
