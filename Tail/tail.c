//------------------------------------------------------------------------
// NAME: Svetoslav Pavlov
// CLASS: XIb
// NUMBER: 22
// PROBLEM: #1
//


#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ERR_BUFF_SIZE 256

//------------------------------------------------------------------------
// FUNCTION: tail()
// This function fiinds the last 10 (or less) rows
// of a given file and prints them in stdout
// PARAMETERS:
// const char *path - This is the path to the 
// file that should be read 
//------------------------------------------------------------------------
int tail(const char *path) {
    int fd = open(path, O_RDONLY);
	char err_buf[ERR_BUFF_SIZE];
	if(fd <= 0){
				int msg = snprintf(err_buf, ERR_BUFF_SIZE,"tail: cannot open '%s' for reading: No such file or directory\n", path);
				write(2, err_buf, msg);
			}

    // Go to end of file
    off_t file_size = lseek(fd, 0, SEEK_END);
    /*if (file_size < 0) {
        print_file_error(path, strerror(errno));
        return -1;
    }
	*/
    char buf[1024];
    int lseek_offset;
    if (file_size < 1024) {
        lseek_offset = file_size;
    } else {
        lseek_offset = 1024;
    }

    // Read the file backwards till 10 lines are reached or file ends
    int linebreaks_count = 0;
    int last_line_pos = 0;
    int bytes_left_to_read = file_size;
    while (bytes_left_to_read > 0 || linebreaks_count == 11) {
        lseek(fd, file_size - lseek_offset, SEEK_SET);
        int bytes_read = read(fd, buf, lseek_offset);
        /*if (bytes_read < 0) {
            print_file_error(path, strerror(errno));
            return -1;
        }
		*/
        buf[bytes_read] = '\0';
        for (int i = bytes_read - 1; i >= 0; i--) {
            if (buf[i] == '\n') {
                linebreaks_count++;
                // When the 11th \n is reached, the 10th line starts from its
                // index + 1
                if (linebreaks_count == 11) {
                    last_line_pos = i + 1;
                    break;
                }
            }
        }

        bytes_left_to_read -= bytes_read;
    }

    for (int i = last_line_pos; buf[i] != '\0'; i++) {
        write(1, &buf[i], 1);
    }
	return 0;
}

int dash(){
// TRQBVA DA SE NAPRAVI DA OBRABOTVA CHERTI4KATA.
}

int main(int argc, char *argv[]){
	int count;
	int file_name;
	char buf[ERR_BUFF_SIZE];
	if(argc == 2){
		if((strcmp(argv[1], "-") == 0)){
			printf("4ert4kata");
			//TRQBVA DA SE DOBAVI FUNKCIQ dash()
		}else{
			tail(argv[1]);
		}
	}
	if(argc > 2){
		for(count = 1; count<argc; count++){
			int file_name = snprintf(buf, ERR_BUFF_SIZE,"==> %s <==\n", argv[count]);
			write(1, buf, file_name);
			tail(argv[count]);
		}
	}
	return 0;
}
