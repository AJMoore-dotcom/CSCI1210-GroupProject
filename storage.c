
#include <stdio.h>
#include <string.h>
#include "student.h"

static int read_field(FILE *fp, char label[],
                      char value[], size_t size)
{
    char line[256];

    if (fgets(line, sizeof(line), fp) == NULL)
    {
        return 0;
    }

    if (strchr(line, '\n') == NULL && !feof(fp))
    {
        return 0;
    }

    line[strcspn(line, "\n")] = '\0';

    int length = strlen(label);

    if (strncmp(line, label, length) != 0)
    {
        return 0;
    }

    if (strlen(line + length) >= size)
    {
        return 0;
    }

    strcpy(value, line + length);
    return 1;
}

int save_students(struct Student students[], int count)
{
    if (count < 0 || count > 100)
    {
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        if (!validate_id(students[i].id) ||
            students[i].course_count != 1 ||
            students[i].courses[0].credits <= 0 ||
            !validate_grade(students[i].courses[0].grade))
        {
            printf("Invalid student record.\n");
            return 0;
        }
    }

    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    int error = 0;

    for (int i = 0; i < count; i++)
    {
        if (fprintf(fp, "ID: %s\n", students[i].id) < 0 ||
            fprintf(fp, "Name: %s\n", students[i].name) < 0 ||
            fprintf(fp, "Major: %s\n", students[i].major) < 0 ||
            fprintf(fp, "Password: %s\n", students[i].password) < 0 ||
            fprintf(fp, "Courses: 1\n") < 0 ||
            fprintf(fp, "Course: %s\n",
                    students[i].courses[0].name) < 0 ||
            fprintf(fp, "Credit: %d\n",
                    students[i].courses[0].credits) < 0 ||
            fprintf(fp, "Grade: %s\n",
                    students[i].courses[0].grade) < 0)
        {
            error = 1;
            break;
        }
    }

    if (fclose(fp) == EOF)
    {
        error = 1;
    }

    if (error)
    {
        printf("Error saving student records.\n");
        return 0;
    }

    return 1;
}

int load_students(struct Student students[])
{
    int count = 0;
    char line[256];
    char extra;

    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("No student file found.\n");
        return 0;
    }

    while (count < 100)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            if (ferror(fp))
            {
                fclose(fp);
                return -1;
            }

            break;
        }

        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "ID: ", 4) != 0 ||
            strlen(line + 4) >= sizeof(students[count].id))
        {
            goto load_error;
        }

        strcpy(students[count].id, line + 4);

        if (!validate_id(students[count].id))
        {
            goto load_error;
        }

        if (!read_field(fp, "Name: ",
                        students[count].name, 100))
        {
            goto load_error;
        }

        if (!read_field(fp, "Major: ",
                        students[count].major, 50))
        {
            goto load_error;
        }

        if (!read_field(fp, "Password: ",
                        students[count].password, 50))
        {
            goto load_error;
        }

        if (fgets(line, sizeof(line), fp) == NULL)
        {
            goto load_error;
        }

        if (sscanf(line, "Courses: %d %c",
                   &students[count].course_count,
                   &extra) != 1)
        {
            goto load_error;
        }

        if (students[count].course_count != 1)
        {
            goto load_error;
        }

        if (!read_field(fp, "Course: ",
                        students[count].courses[0].name, 50))
        {
            goto load_error;
        }

        if (fgets(line, sizeof(line), fp) == NULL)
        {
            goto load_error;
        }

        if (sscanf(line, "Credit: %d %c",
                   &students[count].courses[0].credits,
                   &extra) != 1)
        {
            goto load_error;
        }

        if (students[count].courses[0].credits <= 0)
        {
            goto load_error;
        }

        if (!read_field(fp, "Grade: ",
                        students[count].courses[0].grade, 3))
        {
            goto load_error;
        }

        if (!validate_grade(students[count].courses[0].grade))
        {
            goto load_error;
        }

        count++;
    }

    if (fclose(fp) == EOF)
    {
        printf("Error closing file.\n");
        return -1;
    }

    return count;

load_error:
    printf("Invalid or incomplete student record.\n");
    fclose(fp);
    return -1;
}

int validate_id(char id[])
{
    if (strlen(id) != 9)
    {
        return 0;
    }

    if (id[0] != '9' || id[1] != '0' || id[2] != '0')
    {
        return 0;
    }

    for (int i = 0; i < 9; i++)
    {
        if (id[i] < '0' || id[i] > '9')
        {
            return 0;
        }
    }

    return 1;
}

int validate_grade(char grade[])
{
    if (strcmp(grade, "A") == 0 ||
        strcmp(grade, "A-") == 0 ||
        strcmp(grade, "B+") == 0 ||
        strcmp(grade, "B") == 0 ||
        strcmp(grade, "B-") == 0 ||
        strcmp(grade, "C+") == 0 ||
        strcmp(grade, "C") == 0 ||
        strcmp(grade, "C-") == 0 ||
        strcmp(grade, "D+") == 0 ||
        strcmp(grade, "D") == 0 ||
        strcmp(grade, "D-") == 0 ||
        strcmp(grade, "F") == 0)
    {
        return 1;
    }

    return 0;
}
