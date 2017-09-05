#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



int main(int argc, char **argv)
{
	/*we will read a file and append another file at the end of it, char by char*/
    FILE *from, *to;
    char c;

    if (argc != 3){
        fprintf(stderr, "Usage: %s from file to file", *argv);
        exit (1); /*use exit instead of return, because it already print an error*/
        /*termine the calling, filedescriptors are closed, inheritance, parent process is sent a SIGCHLD signal*/

        /*
         *open the from file for reading
         * */

        if ((from = fopen("argv[1]", "r")) == NULL){ /*note that we use fopen and not open here, open is lower level than fopen, fopen returns a pointer to FILE stream*/
            perror(argv[1]);
            exit(1);
        }
        /*then we open the other file, if to file doesn't exist, fopen will create it. "a" is for writing only, if the file already exist, the content won't be destroyed, new content
         * will append at the end of the file*/
        if ((to = fopen(argv[2], "a")) == NULL){
            perror(argv[2]);
            exit(1);
        }
        /*then writing in the file to*/
        while (c = getc(from) != EOF)
            putc(c, to);

        /*now we close the files*/
        fclose(from);
        fclose(to);
        exit(0);

    }
    return (0);
}
