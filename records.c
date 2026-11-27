#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

int id_search(struct Student students[], int count, char id){
	for(int i = 0, i < count, i++){
		if (strcmp(students[i].id, id)){
			return i;
		}
	}
	return -1;
}

double calculate_gpa(struct Student students[], int ref){
	double gpa_total = 0;
	for(int i = 0, i < students[ref].course_count, i++){
		double gpa;
		if(strcmp(students[ref].courses[i].gpa, "A")){
			gpa = 4.0;
		}else if(strcmp(students[ref].courses[i].gpa, "A-")){
			gpa = 3.7;
		}else if(strcmp(students[ref].courses[i].gpa, "B+")){
			gpa = 3.3;
		}else if(strcmp(students[ref].courses[i].gpa, "B")){
			gpa = 3.0;
		}else if(strcmp(students[ref].courses[i].gpa, "B-")){
			gpa = 2.7;
		}else if(strcmp(students[ref].courses[i].gpa, "C+")){
			gpa = 2.3;
		}else if(strcmp(students[ref].courses[i].gpa, "C")){
			gpa = 2.0;
		}else if(strcmp(students[ref].courses[i].gpa, "C-")){
			gpa = 1.7;
		}else if(strcmp(students[ref].courses[i].gpa, "D+")){
			gpa = 1.3;
		}else if(strcmp(students[ref].courses[i].gpa, "D")){
			gpa = 1.0;
		}else if(strcmp(students[ref].courses[i].gpa, "D-")){
			gpa = 0.0;
		}else if(strcmp(students[ref].courses[i].gpa, "F")){
			gpa = 0.0
		}
	}
	total_gpa += gpa;
	double avarage_gpa = total_gpa / students[ref].course_count;
	return avarage_gpa;
}

void print_record(struct Student students[], int ref, double gpa){
	printf("Student Record for ID:%s\n", students[ref].id);
	printf("Name: %s\n", students[ref].name);
	printf("Major %s\n", students[ref].major);
	for(int i = 0, i < students[ref].course_count, i++){
		printf("Course %d information:\n", i);
		printf("Course name: %s\n", students[ref].courses[i].name);
		printf("Course credits: %d\n", students[ref].courses[i].credits);
		printf("Course grade: %s\n", students[ref].courses[i].grade);
	}
}
void update_profile(struct Student students[], int ref);
bool check_password(struct Student students[], int ref);
