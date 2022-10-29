#include<stdio.h>

int main() {
    int my_var = 20;
    int* my_var_p;
    my_var_p = &my_var;

    printf("Address of my_var: %p\n", my_var_p);
    printf("Address of my_var: %p\n", &my_var);
    printf("Address of my_var_p: %p\n\n", &my_var_p);

    printf("my_var is %d \n", my_var);
    printf("&my_var is %p \n", &my_var);
    printf("my_var_p is %p\n", my_var_p);
    printf("*my_var_p is %d\n", *my_var_p);
    
    my_var += 2;
    printf("\nAfter my_var added 2\n");
    printf("my_var is %d \n", my_var);
    printf("&my_var is %p \n", &my_var);
    printf("my_var_p is %p\n", my_var_p);
    printf("*my_var_p is %d\n", *my_var_p);

    *my_var_p += 2;
    printf("\nAfter *my_var_p added 2\n");
    printf("my_var is %d \n", my_var);
    printf("&my_var is %p \n", &my_var);
    printf("my_var_p is %p\n", my_var_p);
    printf("*my_var_p is %d\n", *my_var_p);

    my_var_p += 2;
    printf("\nAfter my_var_p added 2\n");
    printf("my_var is %d \n", my_var);
    printf("&my_var is %p \n", &my_var);
    printf("my_var_p is %p\n", my_var_p);
    printf("*my_var_p is %d\n\n", *my_var_p);

    printf("Address of my_var: %p\n", &my_var);
    printf("Address of my_var_p: %p\n\n", &my_var_p);

    return 0;
}
