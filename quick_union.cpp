#include <iostream>

using namespace std;

long long  output=1;

long long root(long long *p, long long i)
{
    while (i != *(p + i))
        i = *(p + i);
    return i;
}

void unionEl(long long *p, long long *size_arr, long long el_p, long long el_q)
{
    long long i = root(p, el_p);
    long long j = root(p, el_q);
    if (i == j)
        return;
    if (*(size_arr + i) < *(size_arr + j))
    {
        *(p + i) = j; 
        *(size_arr + j) += *(size_arr + i);
    }
    else
    {
        *(p + j) = i;
        *(size_arr + i) += *(size_arr + j);
    }
}

bool connected(long long *p,long long i, long long j) 
{
    return root(p,i) == root(p,j);
}

void palindrome(long long *p, long long *size_arr,long long start, long long end)
{
    if( start == end)
    {
        return;
    }
    unionEl(p, size_arr, start, end);
    size_arr[end] == 0;
    palindrome(p,size_arr,++start, --end);
}

void display(long long *id, long long  N)
{
    for (long long  i = 1; i <= N; i++)
    {
        cout << id[i] << " ";
    }
    cout << endl;
}

int main()
{
    long long  no_digits, conditions;
    cin >> no_digits;
    cin >> conditions;
    long long id[no_digits+ 1];
    long long sizeArr[no_digits + 1];
    for (long long i = 0; i <= no_digits; i++)
    {
        id[i] = i;
        sizeArr[i] = 1;
    }
    for (long long i = 0; i < conditions; i++)
    {
        long long start, end;
        cin >> start;
        cin >> end;
        palindrome(id, sizeArr, start, end);
    }
    display(id, no_digits);
    display(sizeArr, no_digits);
}
