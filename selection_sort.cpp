#include<iostream>
using namespace std; 

typedef int (*cmpr)(int,int);

int compare(int a, int b)
{
    return (a < b ? -1:1);
}


void display(int* arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}


void exch(int *arr, int i, int j, int n)
{
    display(arr, n);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int *arr, int n, cmpr less)
{
    for (size_t i = 0; i < n; i++)
    {
        int min_index = i;
        for (size_t j = i+1; j < n; j++)
        {
            if(less( arr[j], arr[min_index]) == -1) 
                min_index = j;
        }
        exch(arr, i, min_index, n);
    } 
}


int main()
{
    int n = 5;
    int arr[5] = {-1, 5, -3, 5, 0};
    selection_sort(arr, n, compare);
    return 0;
}