

#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

void addStudent();
void displayStudents();
void searchStudent(int id);
void deleteStudent(int id);
void updateStudent(int id);
char getGrade(float marks);

#endif
