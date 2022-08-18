#include <stdio.h>

int main()
{

    char tumZincirler[5][12] = {{"ATGATGATGC"}, {"TCGCGCTAGC"}, {"CGTCGTAAAC"}, {"TATTTACGAA"}, {"TACTACTACG"}};
    char harfler[5] = "ATGC";
    int bulundu = 0;
    int register1, register2;

    int i = 0;
    while (i < 5)
    {
        int j = i + 1;
        while (j < 5)
        {
            int t = 0;
            while (t < 10)
            {
                if (tumZincirler[i][t] == harfler[0])
                {
                    if (tumZincirler[j][t] != harfler[1])
                        break;
                }
                else if (tumZincirler[i][t] == harfler[1])
                {
                    if (tumZincirler[j][t] != harfler[0])
                        break;
                }
                else if (tumZincirler[i][t] == harfler[2])
                {
                    if (tumZincirler[j][t] != harfler[3])
                        break;
                }
                else
                {
                    if (tumZincirler[j][t] != harfler[2])
                        break;
                }
                if (t == 9)
                {
                    register1 = i + 1;
                    register2 = j + 1;
                    bulundu = 1;
                    printf("%d%d", register1, register2);
                }
                t++;
            }
            j++;
        }
        i++;
    }
    if (bulundu == 0)
    {
        register1 = 0;
        register2 = 0;
    }
    getchar();
    return 0;
}
