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
void print_record(struct Student students[], int ref, double gpa);
int id_search(struct Student students[], int count, char id);
double calculate_gpa(struct Student students[], int ref);
void new_profile(struct Student students[], int count);
void update_profile(struct Student students[], int ref);
bool check_password(struct Student students[], int ref);

#endif
