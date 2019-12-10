#include <cstdio>
const int maxs = 1 << 15;

int main()
{
    char s[maxs];
    // Here! There is no & in scanf("%s", &s);
    scanf("%s", s);
    while (s[0] != '0')
    {
        int D[maxs] = {0};
        D[0] = 1;
        // if ((s[0] - '0') * 10 + (s[1] - '0') <= 26)
        // {
        //     D[1] = 2;
        // }
        // else
        // {
        //     D[1] = 1;
        // }
        int i = 1;
        for (i = 1; s[i] != '\0'; i++)
        {
            // I ignored this situation! There maybe 20/10 in the code!!!
            D[i] = s[i] == '0' ? 0 : D[i - 1];
            if (s[i - 1] > '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
                D[i] += i > 1 ? D[i - 2] : 1;
        }
        printf("%d\n", D[i - 1]);
        scanf("%s", s);
    }
}
