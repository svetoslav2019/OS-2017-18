#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>   
#include <string.h>
#include <sys/types.h>
#define SIZE 1
char **parse_cmdline(const char*);


char **parse_cmdline(const char* cmdline){
	int i, count;
	ssize_t new_res;
	char **new_string;

	cmdline = (char*)malloc(100*sizeof(char));
	new_string = malloc(100*sizeof(char));

	
	for(count=0; cmdline[count]!= '\0'; count++){

		if(cmdline[count] == ' '){
			i++;
		}
		else{
			new_res = write(new_string[i][count], cmdline+i, 1);
			if(new_res<0) perror("write");
		}
		
	}
	return new_string;


}
// int arr[5][10];
//obqsneniq
//for(i=0; i<n; i++) arr[3][6];

int main(){
	char *cmdline;
	
	cmdline = (char*)malloc(100*sizeof(char));
		char buff[100];
		ssize_t died;
		ssize_t wres;
		int i=5;
		while(1){
			died=read(STDIN_FILENO, buff, 1);
			wres = write(cmdline, buff, 1);
			if(died!=EOF) break;
			
			i--;
		}
			
			printf("%zd", died);
			printf("%s", cmdline);
			printf("%d\n", i);
	return 0;
}
