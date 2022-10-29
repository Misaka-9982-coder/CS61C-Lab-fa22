#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char first_name[50];
    char last_name[50];
    char major[50];
    int age;
} s1, s2;

int main() {
    struct Student s3;

    strcpy(s1.first_name, "Henry");
    strcpy(s2.first_name, "Aditya");
    strcpy(s3.first_name, "Sofia");

    printf("s1's position is: %p\n", &s1);
    printf("s2's position is: %p\n", &s2);
    printf("s3's position is: %p\n", &s3);
    
    printf("s1's first_name is: %s\n", s1.first_name);
    printf("s2's first_name is: %s\n", s2.first_name);
    printf("s3's first_name is: %s\n", s3.first_name);
    
    printf("s1's age is %d\n", s1.age);
    s1.age = 20;
    printf("s1's age is %d\n", s1.age);

    printf("s3's age is %d\n", s3.age);
    s3.age = 20;
    printf("s3's age is %d\n", s3.age);
    
    return 0;
}
