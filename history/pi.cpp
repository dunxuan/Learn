#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
        float s = 1;
        float pi = 0;
        float d = 1.0;
        float n = 1.0;
        while(fabs(d) >= 1e-6) {
                pi += d;
                n += 2;
                s *= -1;
                d = s / n;
        }
        pi *= 4;
        cout << pi;

        return 0;
}