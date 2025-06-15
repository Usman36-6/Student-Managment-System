

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char getGrade(float marks)
{
    if (marks >= 90 && marks <= 100)
        return 'A';
    else if (marks >= 80 && marks < 90)
        return 'B';
    else if (marks >= 70 && marks < 80)
        return 'C';
    else if (marks >= 60 && marks < 70)
        return 'D';
    else if (marks >= 50 && marks < 60)
        return 'E';
    else if (marks >= 0 && marks < 50)
        return 'F';
    else
        return '?';
}

int isValidName(const char *name)
{
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z') ||
              name[i] == ' '))
        {
            return 0;
        }
    }
    return 1;
}

int isIdUnique(int id)
{
    if (id <= 0)
        return 0;

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id == id)
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

void addStudent()
{
    Student s;

    while (1)
    {
        printf("Enter ID (must be positive integer): ");
        if (scanf("%d", &s.id) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (s.id <= 0)
        {
            printf("ID must be a positive number.\n");
            continue;
        }

        if (!isIdUnique(s.id))
        {
            printf("Error: Student with ID %d already exists!\n", s.id);
            return;
        }
        break;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    while (strlen(s.name) == 0 || !isValidName(s.name))
    {
        printf("Invalid name. Use only alphabets and spaces.\nEnter Name again: ");
        scanf(" %[^\n]", s.name);
    }

    while (1)
    {
        printf("Enter Marks (0-100): ");
        if (scanf("%f", &s.marks) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (s.marks < 0 || s.marks > 100)
        {
            printf("Marks must be between 0 and 100.\n");
            continue;
        }
        break;
    }

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}


void displayStudents()
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    Student s;
    printf("ID\tName\t\tMarks\tGrade\n");
    printf("---------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp))
    {
        printf("%d\t%-15s\t%.2f\t%c\n",
               s.id, s.name, s.marks, getGrade(s.marks));
    }
    fclose(fp);
}

void searchStudent(int id)
{
    if (id <= 0)
    {
        printf("Invalid ID. Must be positive number.\n");
        return;
    }

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id == id)
        {
            printf("\nStudent Details:\n");
            printf("ID: %d\nName: %s\nMarks: %.2f\nGrade: %c\n",
                   s.id, s.name, s.marks, getGrade(s.marks));
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
    fclose(fp);
}

// Delete student
void deleteStudent(int id)
{
    if (id <= 0)
    {
        printf("Invalid ID. Must be positive number.\n");
        return;
    }

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id != id)
            fwrite(&s, sizeof(Student), 1, temp);
        else
            found = 1;
    }
    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        printf("Student record deleted successfully.\n");
    else
        printf("Student not found.\n");
}

void updateStudent(int id)
{
    if (id <= 0)
    {
        printf("Invalid ID. Must be positive number.\n");
        return;
    }

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id == id)
        {
            printf("Current Details:\n");
            printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);

            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            while (strlen(s.name) == 0 || !isValidName(s.name))
            {
                printf("Invalid name. Use only alphabets and spaces.\nEnter name again: ");
                scanf(" %[^\n]", s.name);
            }

            while (1)
            {
                printf("Enter new marks (0-100): ");
                if (scanf("%f", &s.marks) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (s.marks < 0 || s.marks > 100)
                {
                    printf("Marks must be between 0 and 100.\n");
                    continue;
                }
                break;
            }

            found = 1;
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        printf("Student record updated successfully.\n");
    else
        printf("Student not found.\n");
}



    
