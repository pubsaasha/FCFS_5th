#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t ID1, ID2;

    ID1 = fork();

    if (ID1 == 0) {
        ID2 = fork();

        if (ID2 == 0) {

            printf("Grandchild\n");
        } else {

            printf("Child\n");
        }
    } else {

        printf("Parent\n");
    }

    return 0;
}
