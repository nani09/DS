#include <iostream>
#include <stdlib.h> 
using namespace std;

class QuickFindUF
{
private:
    int  s;           // size
public:
    QuickFindUF(int N, int* pId)
    {
        s = N;
        // pId = new int[N];
        for (int i = 0; i < s; i++)
        {
            *(pId + i) = i;
        }
    }

    void display(int* pId)
    {
        for (size_t i = 0; i < s; i++)
        {
            cout << *(pId + i) << " ";
        }
        cout << endl;
    }

    bool connected(int* pId, int p, int q)
    {
        return *(pId + p) == *(pId + q);
    }

    void unionPQ(int* pId, int p, int q)
    {
        int p_id = *(pId + p);
        int q_id = *(pId + q);
        for (size_t i = 0; i < s; i++)
        {   
            if (*(pId + i) == p_id)
            {
                *(pId + i) = q_id;
            }
        }
    }
};

int main()
{
    int N = 10;
    int* pId = (int*) malloc(sizeof(int)*N);
    QuickFindUF quick_find(N, pId);
    quick_find.unionPQ(pId, 3, 2);
    quick_find.unionPQ(pId, 2, 4);
    quick_find.unionPQ(pId, 5, 8);
    quick_find.unionPQ(pId, 2, 8);
    quick_find.display(pId);
    free(pId);
    return 0;
}