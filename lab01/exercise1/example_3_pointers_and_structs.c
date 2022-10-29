#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    char major[50];
    int age;
} Student;

void update_major(Student *student, char *new_major) {
    /* Approach 1: dereference then use the dot operator */
    // strcpy((*student).major, new_major);
    /* Approach 2: use the arrow operator */
    strcpy(student->major, new_major);
}

int main() {
    Student s1;

    strcpy(s1.major, "chemistry");
    printf("major: %s\n", s1.major);

    update_major(&s1, "biology");
    printf("major: %s\n", s1.major);
}