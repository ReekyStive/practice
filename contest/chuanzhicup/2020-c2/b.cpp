#include <cstdio>
#include <cmath>

int main()
{
    int score;
    scanf("%d", &score);
    double res;

    if (score >= 90)
    {
        res = 4.0;
    }
    else if (score >= 60)
    {
        res = 4.0 - (90 - score) * 0.1;
    }
    else
    {
        int new_score = int(sqrt(score) * 10.0);
        if (new_score >= 90)
        {
            res = 4.0;
        }
        else if (new_score >= 60)
        {
            res = 4.0 - (90 - new_score) * 0.1;
        }
        else
        {
            res = 0.0;
        }
    }

    printf("%.1lf\n", res);

    return 0;
}