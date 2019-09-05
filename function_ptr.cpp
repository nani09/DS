#include <stdio.h>

void A()
{
    printf("Hello");
}

void B( void (*ptr)() )
{
    (*ptr)();
}

int main()
{
    B(&A);
    return 0;
}