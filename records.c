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
void new_profile(struct Student students[], int count, int id){
	students[ref].id = id;
	int answer;
	printf("ID does not match any existing profiles, would you like to make a new profile?\n");
	printf("(1) Yes, (2) No\n");
	while (true){
		if(scanf("%d", &answer) != 1){
			printf("Please enter valid input: \n")
			continue;
		}else if(answer == 1){
			break;
		}else if(answer == 2){
			printf("Goodbye\n");
			return;
		}else {
			printf("Input must be 1 or 2\n");
			continue;
		}
	}
	printf("Please enter Password: ");
	scanf("%49s", students[ref].password);
	printf("\n Please enter Name: ");
	scanf("%99s", students[ref].name);
	printf("\n Please enter Major: ");
	scanf("%49s", students[ref].major);
	printf("\n Please enter number of courses: ");
	while (true){
		if (scanf("%d", students[ref].course_count) != 1){
			printf("\n Please enter a number: ");
			continue;
		}else break;
	for(int i = 0, i < students[ref].course_count, i++){
		printf("\n Please enter name for course %d: ", i);
		scanf("%49s", students[ref].courses[i].name);
		printf("\n Please enter number of credits for course %d: ", i);
		while (true){
			if (scanf("%d", students[ref].courses[i].credits) != 1){
				printf("\n Please enter a number: ");
				continue;
			}else if (students[ref].courses[i].credits > 3 || students[ref].courses[i].credits < 1){
				printf("\n Please enter valid number of credits: ");
				continue;
			}else break;
}
void update_profile(struct Student students[], int ref);
bool check_password(struct Student students[], int ref);
