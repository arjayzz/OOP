#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main(int argc, char* argv[])
{
   // char input[7] = "---H***E+++L+++L///O---P+++O/+-**O---";
    char input[38] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = { Sum, Dif, Mul, Div };
    int S = 0, V;
  //  Content x = 15;
    Content x;
    //double idx;
    int idx;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
        case 0:
            idx = 2;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case 1:
            idx = 0;
            x.p1 = 7;
            x.p2 = 5;
            break;
        case 3:
            idx = 1;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case 5:
            idx = 3;
            x.p1 = 8;
            x.p2 = 4;
            break;
        default:
            break;

        }

        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
