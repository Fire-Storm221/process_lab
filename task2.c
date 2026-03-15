/*
 * Программа создаёт копию себя через fork()
 * и показывает изменение идентификаторов
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("РОДИТЕЛЬСКИЙ ПРОЦЕСС:\n");
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n\n", getppid());
    
    pid_t pid = fork(); 
    
    if (pid == 0) {
        printf("ДОЧЕРНИЙ ПРОЦЕСС (создан через fork):\n");
        printf("PID: %d (новый идентификатор)\n", getpid());
        printf("PPID: %d (идентификатор родителя)\n", getppid());
    } 
    else if (pid > 0) {
        wait(NULL); 
        printf("\nРодительский процесс завершён\n");
    }
    
    return 0;
}
