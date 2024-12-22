#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void arrangeStudents(struct Student students[], int count) {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(struct Student students[], int count) {
    printf("Danh sach sinh vien\n");
    for (int i = 0; i < count; i++) {
        printf("ID %d Ten %s Tuoi %d So dien thoai %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Nguyen Van B", 22, "0987654321"},
        {3, "Nguyen Van C", 21, "0912345678"},
        {4, "Nguyen Van D", 23, "0934567890"},
        {5, "Nguyen Van E", 19, "0976543210"}
    };
    
    int count = 5;

    arrangeStudents(students, count);

    printStudents(students, count);

    return 0;
}


