#include<iostream>
using namespace std; 

typedef int (*cmpr)(int,int);

int compare(int a, int b)
{
    return (a < b ? 1:0);
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
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int *arr, int n, cmpr less)
{
    for (size_t i = 0; i < n; i++)
    {
        
        for (size_t j = i; j > 0; j--)
        {
            if(less(arr[j], arr[j-1])) 
            {
                exch(arr, j, j-1, n);
            }
            else break;
        }
    } 
}


int main()
{
    int n = 7;
    int arr[n] = {-1, 5, -3, 5, 0, 999, 1};
    selection_sort(arr, n, compare);
    display(arr,n);
    return 0;
}