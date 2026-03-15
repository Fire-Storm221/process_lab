/*
 * Программа создаёт процесс с новым кодом через fork() + exec()
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Основная программа (PID: %d)\n", getpid());
    
    pid_t pid = fork(); 
    
    if (pid == 0) {
        printf("Дочерний процесс (PID: %d) запускает ps:\n", getpid());
        execl("/bin/ps", "ps", "-f", NULL);
        
        perror("Ошибка exec");
        return 1;
    } 
    else if (pid > 0) {
        wait(NULL); 
        printf("\nРодительский процесс (PID: %d) завершён\n", getpid());
    }
    
    return 0;
}
