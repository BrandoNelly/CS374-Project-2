#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE_OF_BUFFER 2048


int main(int argc, char *argv[]) {

    char buffer[SIZE_OF_BUFFER];

    if (argc != 2) {
        perror("Error: invalid number of arguments");
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error: could not open file");
        close(fd);
    }


    int count = read(fd, buffer, SIZE_OF_BUFFER);
        if (count == -1) {
            perror("Error: could not read file");
            close(fd);
        }


    write(STDOUT_FILENO, buffer, count);

    close(fd);

}