#include <iostream>
#include <algorithm>
// #include <time.h>
using namespace std;

void quicksort(int *array, int size);
void quicksort(int *array, int left, int right);
int part(int *array, int left, int right, int pivot);

int main()
{
    // int start = clock(), int end;
    // double times;
    const int maxn = 10e4;
    int n, array[maxn];
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> array[i];

    quicksort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;

    // end = clock();
    // times = (end - start) / CLOCKS_PER_SEC;

    return 0;
}

void quicksort(int *array, int size)
{
    quicksort(array, 0, size - 1);
}

void quicksort(int *array, int left, int right)
{
    if (left >= right)
        return;

    int privot = array[(left + right) / 2];
    int index = part(array, left, right, privot);

    quicksort(array, left, index - 1);
    quicksort(array, index, right);
}

int part(int *array, int left, int right, int pivot)
{
    while (left <= right)
    {
        while (array[left] < pivot)
            left++;
        while (array[right] > pivot)
            right--;

        if (left <= right)
        {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }
    return left;
}
