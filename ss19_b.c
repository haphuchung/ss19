#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void sortStudentsByName(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].name[0] > students[j].name[0]) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++)
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
}

int main() {
    Student students[5] = {
        {1, "nguyen van A", 20, "123456789"},
        {2, "nguyen van B", 21, "987654321"},
        {3, "nguyen van C", 22, "456123789"},
        {4, "nguyen van D", 23, "321654987"},
        {5, "nguyen van E", 24, "654987321"}
    };

    printf("\nBefore sorting:\n");
    printStudents(students, 5);

    sortStudentsByName(students, 5);

    printf("\nAfter sorting by name:\n");
    printStudents(students, 5);

    return 0;
}

