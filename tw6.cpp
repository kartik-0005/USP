//Write a C/C++ program to illustrate the race condition.


#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void charatatime(const char *str) {
    const char *ptr;
    int c;
    std::cout.setf(std::ios::unitbuf);  // Set the output to be unbuffered
    for (ptr = str; (c = *ptr++) != 0;) {
        putc(c, stdout);
    }
}

int main() {
    pid_t pid;
    for (int i = 0; i < 3; ++i) {
        if ((pid = fork()) < 0) {
            std::cerr << "fork error." << std::endl;
        } else if (pid == 0) {
            charatatime("output from child\n");
            _exit(0);
        } else {
            charatatime("output from parent\n");
        }
    }

    // Wait for all child processes to finish
    while (wait(nullptr) > 0);

    return 0;
}
