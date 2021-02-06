#include <stdio.h>
#include <Stdlib.h>

int minDraw(int num);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    printf("%i", minDraw(n));
    return 0;
}


int minDraw(int num)
{
    if (num >= 100)
    {
        int draw = num / 100;
        return draw + minDraw( num % 100);
    }
    else if (num >= 20 && num < 100)
    {
        int draw = num / 20;
        return draw + minDraw(num % 20);
    }
    else if (num >=10 && num < 20)
    {
        int draw = num / 10;
        return draw + minDraw(num % 10);
    }
    else if (num >=5 && num < 10)
    {
        int draw = num / 5;
        return draw + minDraw(num % 5);
    }
    else
    {
        return num;
    }
    
}