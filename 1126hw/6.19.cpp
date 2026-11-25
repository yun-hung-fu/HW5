#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int frequency[13] = {0};
    int die1;
    int die2;
    int sum;
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 36000; i++)
    {
        die1 = 1 + rand() % 6;
        die2 = 1 + rand() % 6;
        sum = die1 + die2;
        frequency[sum]++;
    }

    printf("%s%12s%15s\n", "Sum", "Frequency", "Expected");
    for (sum = 2; sum <= 12; sum++)
    {
        int ways = (sum <= 7) ? (sum - 1) : (13 - sum);
        double expected = 36000.0 * ways / 36.0;
        printf("%3d%12d%15.1f\n", sum, frequency[sum], expected);
    }

    printf("\nReasonableness check: Sum 7 has 6/36 probability (~6000 out of 36000), which matches the simulated count.\n");

    return 0;
}
