#ifndef STUDENT_H
#define STUDENT_H

struct Course {

    char name[50];
    int credits;
    char grade[3];
};

struct Student {

    char id[10];
    char name[100];
    char major[50];
    char password[50];

    struct Course courses[10];
    int course_count;
};

int load_students(struct Student students[]);
int save_students(struct Student students[], int count);
int validate_id(char id[]);
int validate_grade(char grade[]);

#endif
