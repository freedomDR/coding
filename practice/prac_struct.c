#include <stdio.h>
#include <malloc.h>

typedef struct AA
{
    int val1;
    int val2;
}A;

int main()
{
    struct AA a[2] = {{1,2}, {3,4}};
    A b[2] = {{1,2}, {3,4}};
    for(int i = 0; i < 2; i++)
    {
        printf("%d %d\n", a[i].val1, a[i].val2);
        printf("%d %d\n", b[i].val1, b[i].val2);
    }
    A *a_pointor = malloc(sizeof(A));
    printf("%d %d\n", a_pointor->val1, a_pointor->val2);
    free(a_pointor);
    return 0;
}
