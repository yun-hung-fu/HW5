#include <stdio.h>

int recursiveMaximum(const int array[], int size);

int main(void)
{
    int values[] = {24, 89, 12, 67, 105, 43, 91};
    int size = sizeof(values) / sizeof(values[0]);
    int maxVal;

    maxVal = recursiveMaximum(values, size);
    printf("Maximum value: %d\n", maxVal);

    return 0;
}

int recursiveMaximum(const int array[], int size)
{
    int maxRest;

    if (size == 1)
    {
        return array[0];
    }

    maxRest = recursiveMaximum(array, size - 1);

    return (array[size - 1] > maxRest) ? array[size - 1] : maxRest;
}
