

/*#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printHeader()
{
    printf(CYAN "+--------------------------------------------+\n");
    printf("|        Student Management System           |\n");
    printf("+--------------------------------------------+\n" RESET);
}

void printMenu()
{
    printf(YELLOW "🔹 1. Add Student\n");
    printf("🔹 2. Display All\n");
    printf("🔹 3. Search Student\n" RESET);
    printf(RED "🔸 4. Update Student\n");
    printf("🔸 5. Delete Student\n" RESET);
    printf(GREEN "✅ 6. Exit\n" RESET);
}

void waitForEnter()
{
    printf(YELLOW "\nPress Enter to continue..." RESET);
    while (getchar() != '\n')
        ;      
    getchar(); 
}

int main()
{
    int choice, id;

    do
    {
        clearScreen();
        printHeader();
        printMenu();
        printf(BLUE "Enter your choice: " RESET);
        if (scanf("%d", &choice) != 1)
        {

            printf(RED "❌ Invalid input. Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ;
            waitForEnter();
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            searchStudent(id);
            break;
        case 4:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            updateStudent(id);
            break;
        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            deleteStudent(id);
            break;
        case 6:
            printf(GREEN "\nExiting the program... Goodbye!\n" RESET);
            break;
        default:
            printf(RED "❌ Invalid choice. Please try again.\n" RESET);
        }

        if (choice != 6)
        {
            waitForEnter();
        }

    } while (choice != 6);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printHeader()
{
    printf(CYAN "+--------------------------------------------+\n");
    printf("|        Student Management System           |\n");
    printf("+--------------------------------------------+\n" RESET);
}

void printMenu()
{
    printf(YELLOW "\xF0\x9F\x94\xB9 1. Add Student\n");
    printf("\xF0\x9F\x94\xB9 2. Display All\n");
    printf("\xF0\x9F\x94\xB9 3. Search Student\n" RESET);
    printf(RED "\xF0\x9F\x94\xB8 4. Update Student\n");
    printf("\xF0\x9F\x94\xB8 5. Delete Student\n" RESET);
    printf(GREEN "\xE2\x9C\x85 6. Exit\n" RESET);
}

void waitForEnter()
{
    printf(YELLOW "\nPress Enter to continue..." RESET);
    while (getchar() != '\n')
        ;
    getchar();
}

int main()
{
    int choice, id;
    do
    {
        clearScreen();
        printHeader();
        printMenu();
        printf(BLUE "Enter your choice: " RESET);
        if (scanf("%d", &choice) != 1)
        {
            printf(RED "\n\xE2\x9D\x8C Invalid input. Please enter a number.\n" RESET);
            while (getchar() != '\n')
                ;
            waitForEnter();
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            searchStudent(id);
            break;
        case 4:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            updateStudent(id);
            break;
        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            deleteStudent(id);
            break;
        case 6:
            printf(GREEN "\nExiting the program... Goodbye!\n" RESET);
            break;
        default:
            printf(RED "\xE2\x9D\x8C Invalid choice. Please try again.\n" RESET);
        }

        if (choice != 6)
        {
            waitForEnter();
        }
    } while (choice != 6);

    return 0;
}
