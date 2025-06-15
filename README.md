Student Management System - Project Description
📌 Introduction
The Student Management System (SMS) is a console-based application developed in C programming language. It allows educational institutions to manage student records efficiently by performing basic CRUD (Create, Read, Update, Delete) operations. The system stores student data in a file, ensuring persistence even after the program terminates.
🎯 Key Features
📝 Add New Student
Input student details: ID, Name, Marks
Automatically calculates Grade based on marks
Ensures unique student ID to avoid duplicates
👀 Display All Students
Shows a formatted list of all students
Displays ID, Name, Marks, and Grade
🔍 Search Student by ID
Finds and displays a student’s details using their unique ID
✏️ Update Student Record
Modifies name and marks of an existing student
Automatically updates the grade
❌ Delete Student Record
Removes a student’s record using their ID
📂 File-Based Storage
Data is stored in "data.txt"
Records persist even after program restarts
🛠️ Technical Details
Programming Language: C
Data Storage: Text file (data.txt)
Data Structure: struct Student containing:
id (int)
name (char array)
marks (float)
Grading System:
A (90-100)
B (80-89)
C (70-79)
D (60-69)
E (50-59)
F (Below 50)
🚀 How It Works
Menu-Driven Interface:
Users interact via a console menu.
Options:
text
1. Add Student  
2. Display All Students  
3. Search Student  
4. Update Student  
5. Delete Student  
6. Exit  
File Handling:
Uses fopen(), fwrite(), fread(), fclose() for data storage.
Temporary files (temp.txt) help in updating & deleting records.
Error Handling:
Checks for duplicate IDs before adding a student.
Validates file operations (e.g., if data.txt exists).
📊 Benefits
✅ Simple & Efficient – No database required, uses file storage.
✅ User-Friendly – Easy-to-navigate console interface.
✅ Persistent Data – Records remain saved after program exit.
✅ Scalable – Can be extended with more features (e.g., sorting, statistics).
🎓 Conclusion
This Student Management System is a practical C project that demonstrates file handling, structures, and basic CRUD operations. It’s ideal for learning C programming concepts while building a functional application.



