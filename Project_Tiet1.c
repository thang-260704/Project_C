#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct Date {
    int month, day, year;
};

typedef struct {
    int id;
    char classId[10];
    char fullName[30];
    struct Date dob;
    char gender[10];
    char email[50];
    char phoneNumber[20];
} Student;

void displayGoodbyeMessage() {
    printf("----------Thank You----------\n");
    printf("----------See You Soon-------\n \n");
}

void displayStudentMenu() {
    printf("\t \tMENU \n");
    printf("------------------------------ \n");
    printf("------------------------------ \n");
    printf("1. Display list of students \n");
    printf("2. Add students \n");
    printf("3. Edit student information \n");
    printf("4. Delete students \n");
    printf("5. Search for students by name \n");
    printf("6. Sort the student list by name \n");
    printf("7. Check input data for students \n");
    printf("8. Data storage \n");
    printf("0. Exit \n");
}

void displayMainMenu() {
    printf("***Student Management System Using C*** \n \n");
    printf("          CHOOSE YOUR ROLE \n");
    printf("------------------------------ \n");
    printf("------------------------------ \n");
    printf("[1]. Student \n");
    printf("[2]. Teacher \n");
    printf("[0]. Exit The Program \n");
    printf("------------------------------ \n");
    printf("------------------------------ \n");
    printf("Enter The Choice: ");
}

int main() {
    int initialStudentCount = 5;
    int totalStudents = initialStudentCount;
    Student *studentList = malloc(initialStudentCount * sizeof(Student));
    if (!studentList) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    memcpy(studentList, (Student[]) {
        {1, "ENG_KS24B", "Nguyen Quyet Thang", {7, 26, 2004}, "Male", "nguyentrung27092006@gmail.com", "0983861111"},
        {2, "ENG_KS24B", "Nguyen Sy Trung", {6, 1, 2006}, "Male", "quyetthang@gmail.com", "0983861112"},
        {3, "ENG_KS24B", "Nguyen Manh Hung", {12, 2, 2006}, "Male", "manhhung123@gmail.com", "0983861113"},
        {4, "ENG_KS24B", "Nguyen Tuan Dung", {3, 12, 2006}, "Male", "dungdeptrai@gmail.com", "0983861114"},
        {5, "ENG_KS24B", "Tran Anh Dung", {28, 2, 2006}, "Male", "dunganh01@gmail.com", "0983861115"}
    }, initialStudentCount * sizeof(Student));

    char enteredEmail[50];
    char enteredPassword[50];
    int mainMenuChoice;
    int studentMenuChoice;

    printf("***Student Management System Using C*** \n \n");
    printf("          LOGIN \n");
    printf("------------------------------ \n");
    printf("------------------------------ \n");
    printf("EMAIL :");
    fgets(enteredEmail, 50, stdin);
    enteredEmail[strcspn(enteredEmail, "\n")] = '\0';
    printf("Password :");
    fgets(enteredPassword, 50, stdin);
    enteredPassword[strcspn(enteredPassword, "\n")] = '\0';

    char adminEmail[50] = "nguyentrung27092006@gmail.com";
    char adminPassword[50] = "nguyentrung2709";
    if (strcmp(adminEmail, enteredEmail) != 0 || strcmp(adminPassword, enteredPassword) != 0) {
        printf("Wrong login name or password admin !\n \n \n");
        displayGoodbyeMessage();
        free(studentList);
        return 1;
    }

    displayMainMenu();
    scanf("%d", &mainMenuChoice);
    getchar();
    switch (mainMenuChoice) {
        case 0:
            break;
        case 1:
            displayStudentMenu();
            printf("------------------------------ \n");
            printf("Enter The Choice: ");
            scanf("%d", &studentMenuChoice);
            getchar();
            switch (studentMenuChoice) {
                case 0:
                    displayGoodbyeMessage();
                    break;
                case 1:
                    printf("%-5s %-10s %-20s %-4s %-4s %-8s %-10s %-30s %-20s\n", "ID", "ClassID", "Name", "M", "D", "Y", "Gender", "Email", "Phone");
                    printf("--------------------------------------------------------------------------------------------------------------------\n");
                    for (int i = 0; i < totalStudents; i++) {
                        printf("%-5d %-10s %-20s %-4d %-4d %-8d %-10s %-30s %-20s\n",
                               studentList[i].id, studentList[i].classId, studentList[i].fullName,
                               studentList[i].dob.month, studentList[i].dob.day, studentList[i].dob.year,
                               studentList[i].gender, studentList[i].email, studentList[i].phoneNumber);
                    }
                    break;
                case 2:
                    printf("Please enter the number of students you want to add: ");
                    int newStudentCount;
                    scanf("%d", &newStudentCount);
                    getchar();
                    studentList = realloc(studentList, (totalStudents + newStudentCount) * sizeof(Student));
                    if (!studentList) {
                        printf("Memory allocation failed!\n");
                        return 1;
                    }
                    for (int i = 0; i < newStudentCount; i++) {
                        printf("Please enter Student ID [%d]: ", totalStudents + i + 1);
                        scanf("%d", &studentList[totalStudents + i].id);
                        getchar();
                        printf("Please enter ClassID [%d]: ", totalStudents + i + 1);
                        fgets(studentList[totalStudents + i].classId, 10, stdin);
                        studentList[totalStudents + i].classId[strcspn(studentList[totalStudents + i].classId, "\n")] = '\0';
                        printf("Please enter Name [%d]: ", totalStudents + i + 1);
                        fgets(studentList[totalStudents + i].fullName, 30, stdin);
                        studentList[totalStudents + i].fullName[strcspn(studentList[totalStudents + i].fullName, "\n")] = '\0';
                        printf("Please enter DOB.Month [%d]: ", totalStudents + i + 1);
                        scanf("%d", &studentList[totalStudents + i].dob.month);
                        getchar();
                        printf("Please enter DOB.Day [%d]: ", totalStudents + i + 1);
                        scanf("%d", &studentList[totalStudents + i].dob.day);
                        getchar();
                        printf("Please enter DOB.Year [%d]: ", totalStudents + i + 1);
                        scanf("%d", &studentList[totalStudents + i].dob.year);
                        getchar();
                        printf("Please enter Gender [%d]: ", totalStudents + i + 1);
                        fgets(studentList[totalStudents + i].gender, 10, stdin);
                        studentList[totalStudents + i].gender[strcspn(studentList[totalStudents + i].gender, "\n")] = '\0';
                        printf("Please enter Email [%d]: ", totalStudents + i + 1);
                        fgets(studentList[totalStudents + i].email, 50, stdin);
                        studentList[totalStudents + i].email[strcspn(studentList[totalStudents + i].email, "\n")] = '\0';
                        printf("Please enter Phone [%d]: ", totalStudents + i + 1);
                        fgets(studentList[totalStudents + i].phoneNumber, 20, stdin);
                        studentList[totalStudents + i].phoneNumber[strcspn(studentList[totalStudents + i].phoneNumber, "\n")] = '\0';
                    }
                    totalStudents += newStudentCount;
                    printf("List added successfully!\n");
                    break;
                default:
                    printf("Invalid selection.\n");
            }
            break;
        default:
            printf("Invalid selection.\n");
    }
    free(studentList);
    displayGoodbyeMessage();
    return 0;
}
