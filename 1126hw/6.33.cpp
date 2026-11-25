#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(const int b[], int low, int high, int searchKey);
void bubbleSort(int a[], int size);

int main(void)
{
    int frequency[13] = {0};
    int sortedFreq[11];
    int die1;
    int die2;
    int sum;
    int i;
    int key;
    int result;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 36000; i++)
    {
        die1 = 1 + rand() % 6;
        die2 = 1 + rand() % 6;
        sum = die1 + die2;
        frequency[sum]++;
    }

    for (i = 0; i < 11; i++)
    {
        sortedFreq[i] = frequency[i + 2];
    }

    bubbleSort(sortedFreq, 11);

    printf("Sorted frequencies:\n");
    for (i = 0; i < 11; i++)
    {
        printf("Index %2d: %d\n", i, sortedFreq[i]);
    }

    printf("\nEnter a frequency value to search: ");
    scanf("%d", &key);

    result = binarySearch(sortedFreq, 0, 10, key);

    if (result != -1)
    {
        printf("Found at subscript %d (value = %d)\n", result, sortedFreq[result]);
    }
    else
    {
        printf("Value %d not found.\n", key);
    }

    return 0;
}

int binarySearch(const int b[], int low, int high, int searchKey)
{
    int middle;

    if (low > high)
    {
        return -1;
    }

    middle = (low + high) / 2;

    if (searchKey == b[middle])
    {
        return middle;
    }
    else if (searchKey < b[middle])
    {
        return binarySearch(b, low, middle - 1, searchKey);
    }
    else
    {
        return binarySearch(b, middle + 1, high, searchKey);
    }
}

void bubbleSort(int a[], int size)
{
    int pass;
    int j;
    int temp;

    for (pass = 0; pass < size - 1; pass++)
    {
        for (j = 0; j < size - 1 - pass; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
