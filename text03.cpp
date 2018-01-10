//
// Created by antonio on 18-1-9.
//


/*
 * 题目3：排序
① 生成100个在[200, 1000]之间的整数保存数组A中，以此数组元素作为关键字，采用希尔排序算法按非递减方式进行排序，给出操作的结果及相应的操作次数；
③ 生成200个在[200, 10000]之间的整数保存数组A中，以此数组元素作为关键字，采用快速排序算法按非递减方式进行排序，给出操作的结果及相应的操作次数；
④ 生成500个在[200, 10000]之间的整数保存数组A中，以此数组元素作为关键字，采用堆排序算法按非递减方式进行排序，给出操作的结果及相应的操作次数；
⑤ 主函数通过调用函数实现以上操作。
 * */

#include <iostream>

using namespace std;

int quickSort(int arr[], int left, int right);

int ShellSort(int a[], int n);

int heapSort(int arr[], int n);

int main03()
{
    int *randNum[3], count[3];

    randNum[0] = new int[100];
    randNum[1] = new int[200];
    randNum[2] = new int[500];


    for (int i = 0; i < 100; ++i)
    {
        randNum[0][i] = 200 + rand() % 800;// NOLINT
        cout << randNum[0][i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 200; ++i)
    {
        randNum[1][i] = 200 + rand() % 9800;// NOLINT
        cout << randNum[1][i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 500; ++i)
    {
        randNum[2][i] = 200 + rand() % 9800; // NOLINT
        cout << randNum[2][i] << " ";
    }
    cout << endl << endl;

    count[0] = ShellSort(randNum[0], 100);
    count[1] = quickSort(randNum[1], 0, 199);
    count[2] = heapSort(randNum[2], 500);

    for (int i = 0; i < 100; ++i)
    {
        cout << randNum[0][i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 200; ++i)
    {
        cout << randNum[1][i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 500; ++i)
    {
        cout << randNum[2][i] << " ";
    }
    cout << endl << endl;

    delete[] randNum[0];
    delete[] randNum[1];
    delete[] randNum[2];

    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

int heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    }
}

int ShellSort(int a[], int n)
{
    int i, j, k, temp;
    for (i = n / 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (a[k + i] >= a[k])
                {
                    break;
                }
                else
                {
                    temp = a[k];
                    a[k] = a[k + i];
                    a[k + i] = temp;
                }
            }
        }
    }
}

int quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
    {
        quickSort(arr, left, j);
    }

    if (i < right)
    {
        quickSort(arr, i, right);
    }
}