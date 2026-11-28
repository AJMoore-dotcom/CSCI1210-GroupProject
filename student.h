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

int load_students(struct Student students[]); //Augustine
int save_students(struct Student students[], int count); //Augustine
int validate_id(char id[]); // Augustine
int validate_grade(char grade[]); // Augustine
void print_record(struct Student students[], int ref, double gpa); //Annabeth
int id_search(struct Student students[], int count, char id); // Annabeth
double calculate_gpa(struct Student students[], int ref); //Annabeth
void update_profile(struct Student students[], int count, int ref); //Annabeth
int check_password(struct Student students[], int ref); //Onix
void new_profile(struct Student students[], int count); //Onix
int id_duplicate(struct Student students[], int count, char id[]) //Onix

#endif
