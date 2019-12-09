#include <iostream>
using namespace std;
#define n 31

int main()
{
    // int n = 31;
    int size = 0;
    int D[n + 1] = {0};
    int A[n + 1] = {0};
    // D[0] = D[1] = 0;
    // A[0] = A[1] = A[2] = 0;
    D[0] = A[0] = A[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        // A[i - 1] = D[i - 2] + A[i - 3];
        // D[i] = 3* D[i - 2] + 2 * A[i - 1];
        D[i] = D[i - 2] + 2 * A[i - 1];
        A[i] = D[i - 1] + A[i - 2];
    }
    scanf("%d", &size);
    while (size >= 0)
    {
        if (size % 2 == 1)
        {
            cout<<0<<endl;
        }
        else
        {
            printf("%d\n", D[size]);
        }
        scanf("%d", &size);
    }
}