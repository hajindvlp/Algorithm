#include <stdio.h>
#include <stdlib.h>
using namespace std;

int com(const void*_elem1, const void*_elem2)
{
    int*elem1 = (int*)_elem1;
    int*elem2 = (int*)_elem2;

    if (*elem1>*elem2)
        return 1;
    else if (*elem1<*elem2)
        return -1;
    else
        return 0;
}

int main()
{

    int input;
    int arr[50001] = { 0, };
    int arr2[50001] = { 0, };
    int length = sizeof arr / sizeof arr[0];
    int temp = 0;

    scanf("%d", &input);

    for (int i = 0; i < input; i++)
    {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }

    qsort = ((void*)arr2, length, sizeof(int), com);

    for (int i = 0; i < input; i++)
        for (int j = 0; j < input; j++)
            if (arr2[i] == arr[j])
                printf("%d ", j);
    return 0;
}
