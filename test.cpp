// #include <iostream>
// #include <numeric> 
// using namespace std;



// bool array_sum(int *arr, int arr_size, int i, int j, int K)
// {   
//     int sol = 0;
//     for(int p = i; p < j ; p++)
//     {
//         // cout << "arr[p] = " <<arr[p] << endl;
//         sol += arr[p];
//     }
//     bool res = (sol <= K ? 1:0);
//     cout << "i = "<< i << "j = "<< j << " sol = " << sol << " res = "<< res<< endl;
//     return res ; 
// }

// int comp(const void *elem1, const void *elem2)
// {
//     int f = *((int *)elem1);
//     int s = *((int *)elem2);
//     return f - s;
// }

// int main()
// {
//     int T, N, M, K, el,sol = 0;
//     cin >> T;
//     for (size_t i = 0; i < T; i++)
//     {
//         int count = 0;
//         cin >> N >> M >> K;
//         int arr[N*M];
//         for (size_t i = 0; i < N; i++)
//         {
//             cin >> el;
//             arr[i] = el;
//         }
//         for (size_t i = N; i < (M*N); i++)
//         {
//             arr[i] = arr[count++];
//             if(count == N) count = 0;
//         }
//         // qsort(arr, N*M, sizeof(arr[0]), comp);
//         for (size_t i = 0; i < M*N; i++)
//         {
//             for (size_t j = i+1; j < M*N ; j++)
//             {
//                 if(array_sum(arr, N*M, i, j, K)) sol++;
//             }     
//         }
//         cout << sol << endl;
//     }
// }



#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void display(const vector<int> &v)
{
    std::copy(v.begin(), v.end(),
    std::ostream_iterator<int>(std::cout, " "));
}

vector<int> rotateArray(vector<int> &A, int B) {
    vector<int> ret(A.size(),0); 
    cout << A.size() << endl;
    for (int i = 0; i <A.size(); i++) {
        int k = (i+B)%A.size();
        ret.insert(ret.begin()+k,A[i]);
    }
    return ret; 
}

int main() 
{
    vector<int> A = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
    int index = 0;
    vector<int> result;
    string s;
    for (size_t i = 0; i < A.size(); i++)
    {
        s += to_string(A[i]);
    }
    cout << s << endl;
    long long sum = stoi(s);
    sum = sum+1;
    cout << sum << endl;
    // int temp = sum;
    // while(sum > 0)
    // {
    //     temp = sum%10;
    //     sum = sum/10;
    //     result.push_back(temp);
    // }
    // reverse(result.begin(), result.end());
    // display(result);
}
