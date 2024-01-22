#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE_OF_BUFFER 2048


int main(int argc, char *argv[]) {

    char buffer[SIZE_OF_BUFFER];
    int count, fd;

   // fd = open(filename, O_RDONLY);

    if(argc == 1) {
        fd = STDIN_FILENO;  
        while((count = read(fd, buffer, SIZE_OF_BUFFER)) > 0){
            write(STDOUT_FILENO, buffer, count);
        }

    } else {
        for(int i = 0; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            count = read(fd, buffer, SIZE_OF_BUFFER);
            write(STDOUT_FILENO, buffer, count);
            close(fd);
        }
    }


}