#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float det(float* A, float* B, float* C)
{
    return A[0] * B[1] * C[2] +
           B[0] * C[1] * A[2] +
           C[0] * A[1] * B[2] -
           A[0] * C[1] * B[2] -
           B[0] * A[1] * C[2] -
           C[0] * B[1] * A[2];
}

int main()
{
    float X[3], Y[3], I[3] = {1, 1, 1};
    while (cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2])
    {
        float S[3];
        for (int i = 0; i < 3; ++i)
            S[i] = X[i] * X[i] + Y[i] * Y[i];
        float A = det(X, Y, I);
        float B = -det(S, Y, I);
        float C = det(S, X, I);
        float D = -det(S, X, Y);
        float r = sqrt((B * B + C * C - 4 * A * D) / (4 * A * A));
        cout << setprecision(2) << fixed << 2 * r * M_PI << '\n';
    }
}
