
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char getGrade(float marks)
{
    if (marks >= 90&&marks<=100)
        return 'A';
    else if (marks >= 80&&marks<=90)
        return 'B';
    else if (marks >= 70&&marks<=80)
        return 'C';
    else if (marks >= 50&&marks<=60)
        return 'D';
       
    else
        return 'F';
    
}

void addStudent()
{
    FILE *fp = fopen("data.txt", "a");
    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudents()
{
    FILE *fp = fopen("data.txt", "r");
    Student s;
    printf("ID   \t    Name\t\t    Marks\t     Grade\n");
    printf("------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp))
    {
        printf("%d\t%-15s\t%.2f\t%c\n", s.id, s.name, s.marks, getGrade(s.marks));
    }
    fclose(fp);
}

void searchStudent(int id)
{
    FILE *fp = fopen("data.txt", "r");
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id == id)
        {
            printf("ID: %d\nName: %s\nMarks: %.2f\nGrade: %c\n", s.id, s.name, s.marks, getGrade(s.marks));
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
    fclose(fp);
}

void deleteStudent(int id)
{
    FILE *fp = fopen("data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
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
        printf("Record deleted.\n");
    else
        printf("Record not found.\n");
}

void updateStudent(int id)
{
    FILE *fp = fopen("data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if (s.id == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);
            found = 1;
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    if (found)
        printf("Record updated.\n");
    else
        printf("Record not found.\n");
}

