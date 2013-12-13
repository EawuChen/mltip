#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define LENGTH 1024

typedef int (*callback_func) (char *);

FILE *open_file(const char *file_name, const char *mode)
{
    FILE *fp = NULL;

    fp = fopen(file_name, mode);
    if (NULL == fp) {
	fprintf(stdout, "Cant open file:%s\n", file_name);
	exit(-1);
    }
    return fp;
}


char *read_line(FILE *fp, long *pos,  char *line)
{
    char c;
    int result;

    if (NULL == line) {
	fprintf(stderr, "Enpty pointer.\n");
	exit(-1);
    }

    if ((result = fseek(fp, *pos, SEEK_SET)) != 0) {
	fprintf(stderr, "Seek file failed.\n");
	exit(-1);
    }

    while ((c = getc(fp)) != EOF) {
	if (c == '\n') {
	    *pos = ftell(fp);
	    break;
	}
	*line = c;
	line ++;
    }
    *line = '\0';

    return (c == EOF) ? NULL : line;
}  


void close_file(FILE *fp)
{
    if (fclose(fp) != 0) {
	fprintf(stderr, "Close file failed.\n");
	exit(-1);
    }
}


int handle_line(char *line)
{
    if (NULL == line || sizeof(line) == 0) {
	fprintf(stderr, "Enpty pointer.\n");
	exit(-1);
    }

    fprintf(stdout, "line is:%s\n", line);

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LENGTH] = {'0'};
    long pos = 0;

    if (argc < 2) {
	fprintf(stderr, "Usage:\n\t./a.out filename\n");
	exit(-1);
    }

    fp = open_file(argv[1], "r");
    
    while (read_line(fp, &pos, line)) {
	handle_line(line);
	memset(line, '0', LENGTH);
    }
    close_file(fp);

    return 0;
}
