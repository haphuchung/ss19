#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudentById(int id, Student students[], int *currentLength) {
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            printf("\nStudent with ID %d has been deleted.\n", id);
            return;
        }
    }
    printf("\nStudent with ID %d not found.\n", id);
}

void printStudents(Student students[], int currentLength) {
    printf("\nCurrent list of students:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "nguyen van A", 20, "123456789"},
        {2, "nguyen van B", 21, "987654321"},
        {3, "nguyen van C", 22, "456123789"},
        {4, "nguyen van D", 23, "321654987"},
        {5, "nguyen van E", 24, "654987321"}
    };
    int currentLength = 5;

    printStudents(students, currentLength);

    int idToDelete;
    printf("\nEnter the ID of the student to delete: ");
    scanf("%d", &idToDelete);

    deleteStudentById(idToDelete, students, &currentLength);

    printStudents(students, currentLength);

    return 0;
}

