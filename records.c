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
		total_gpa += gpa;
	}
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
void update_profile(struct Student students[], int count, int ref){
	int answer;
	printf("Do you want to update your profile?\n");
	printf("(1) Yes (2) No\n");
	while (scanf("%d", &answer) != 1 || answer != 1 || answer != 2){
		printf("Invalid input, please enter either 1 or 2\n")
	}
	if (answer == 2){
		return;
	}
	while (answer != 0){
		printf("What would you like to edit?\n");
		printf("(1) Name, (2) ID, (3) Password, (4) Major, (5) Course Information, (0) Cancel\n");
		while (scanf("%d", &answer) != 1 || answer < 0 || answer > 5){
			printf("Please enter a number between 0 and 5\n");
		}
		if (answer == 0){
			continue;
		}
		if (answer == 1){
			printf("Please enter new name: ");
			scanf("%99s", student[ref].name);
		}
		if (answer == 2){
			printf("Please enter new ID: ");
			int temp_id;
			while (scanf("%9s", temp_id), !validate_id(students[ref].id) || !duplicate_id(students, count, temp_id)){
				if (!validate_id(students[ref].id)){
					printf("\n Invalid ID, please enter a valid ID: ");
				}else {
					printf("\n Duplicate ID, please enter a unique ID: ");	
				}
			}
			students[ref].id = temp_id;
			free(temp_id);
		}
		if (answer == 3){
			printf("Please enter a new password: ");
			scanf("%39s", students[ref].
		}
		printf("Would you like to make more edits?\n");
		printf("(1) Yes (2) No");
		while (scanf("%d", &answer) != 1 || answer != 1 || answer != 2){
			printf("Invalid input, please enter either 1 or 2\n")
		}
		if (answer == 1) continue;
		if (answer == 2) {
			printf("Goodbye \n");
			return;
		}
	}
	return;
}

