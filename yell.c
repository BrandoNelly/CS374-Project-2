#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define SIZE_OF_BUFFER 2048


int main(int argc, char *argv[]) {

    char buffer[SIZE_OF_BUFFER];
    int count, fd;

   // fd = open(filename, O_RDONLY);

    if(argc == 1) {
        fd = STDIN_FILENO;  
        while((count = read(fd, buffer, SIZE_OF_BUFFER)) > 0){
            for(int i = 0; i < count; i++) {
                buffer[i] = toupper(buffer[i]);
            }
            write(STDOUT_FILENO, buffer, count);
        }

    } else {
        for(int i = 0; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            count = read(fd, buffer, SIZE_OF_BUFFER);

            for(int i = 0; i < count; i++) {
                buffer[i] = toupper(buffer[i]);
            }

            write(STDOUT_FILENO, buffer, count);
            close(fd);
        }
    }


}