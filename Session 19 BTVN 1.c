#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void deleteStudent(int id, struct Student students[], int *count){
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Sinh vien voi ID %d da duoc xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}


void printStudents(struct Student students[], int count) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Tên: %s, Tuoi: %d, So dien thoai: %s\n",
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
    deleteStudent(3, students, &count);
    printStudents(students, count);

    return 0;
}

