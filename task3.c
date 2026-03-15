/*
 * Программа создаёт процесс с новым кодом через fork() + exec()
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Основная программа (PID: %d)\n", getpid());
    
    pid_t pid = fork(); // создаём новый процесс
    
    if (pid == 0) {
        // Дочерний процесс заменяет свой код на команду "ps -f"
        printf("Дочерний процесс (PID: %d) запускает ps:\n", getpid());
        execl("/bin/ps", "ps", "-f", NULL);
        
        // Если дошли до сюда - ошибка
        perror("Ошибка exec");
        return 1;
    } 
    else if (pid > 0) {
        wait(NULL); // ждём дочерний процесс
        printf("\nРодительский процесс (PID: %d) завершён\n", getpid());
    }
    
    return 0;
}