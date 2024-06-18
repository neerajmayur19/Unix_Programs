#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int global_variable = 10;

void second(void)
{
    printf("Inside Second Function\n");
    longjmp(buf,1);
}
void first(void)
{
    register int register_variable = 20;
    volatile int volatile_variable = 30;
    int automatic_variable = 40;

    printf("Before Long Jump:\n");
    printf("Global Variable : %d\n", global_variable);
    printf("Register Variable : %d\n", register_variable);
    printf("Volatile Variable : %d\n", volatile_variable);
    printf("Automatic Variable : %d\n", automatic_variable);

    if(setjmp(buf)==0)
    {
        global_variable = 11;
        register_variable = 21;
        volatile_variable = 31;
        automatic_variable = 41;
        second();
    }
    else
    {
        printf("After Long Jump:\n");
        printf("Global Variable : %d\n", global_variable);
        printf("Register Variable : %d\n", register_variable);
        printf("Volatile Variable : %d\n", volatile_variable);
        printf("Automatic Variable : %d\n", automatic_variable);
    }
}
int main()
{
    first();
    return 0;
}