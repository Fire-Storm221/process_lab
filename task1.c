/*
 * Программа 1: выводит идентификатор текущего и родительского процесса
 */

#include <stdio.h>
#include <unistd.h>

int main() {
    // getpid() возвращает ID текущего процесса
    // getppid() возвращает ID родительского процесса
    printf("PID текущего процесса: %d\n", getpid());
    printf("PID родительского процесса: %d\n", getppid());
    return 0;
}
