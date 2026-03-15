/*
 * Программа выводит идентификатор текущего и родительского процесса
 */

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Текущий процесс (PID): %d\n", getpid());
    printf("Родительский процесс (PPID): %d\n", getppid());
    return 0;
}