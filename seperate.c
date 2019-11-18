#include <stdio.h>
#include <stdlib.h>

void read(char *filename, FILE *rfp, FILE *wfp);
void write(char * filename, char c, FILE *wfp);

int main(void) {
    char file[30];
    printf("Enter the css file name you want to format with: (include the .css) ");
    scanf("%s", file);
    
    //char file[] = "app.min.css";
	FILE *rfp;
    FILE *wfp;
	read(file, rfp, wfp);
	return 0;
}

void read(char *filename, FILE* rfp, FILE *wfp) {
	char c;
	printf("Opening the file in read mode \n");

	rfp = fopen(filename, "r");
    wfp = fopen("formatted.css","w");

	if (rfp ==  NULL) {
		printf("Could not open file \n");
        return;
	}

	printf("Reading the file \n");
	while (1) {
		c = fgetc(rfp);
		if (c == EOF) {
			break;
		}
        write("format.css", c, wfp);
		//printf ( "%c", c ) ;

	}
	printf("Closing the file test.c \n") ;
	fclose(rfp);
    fclose(wfp);
}

void write(char *filename, char c, FILE *wfp) {
    if (c == '{') {
        fputc('\n', wfp);
        fputc(c, wfp);
        fputc('\n', wfp);
        fputc('\t', wfp);
    }
    else if (c == '}') {
        fputc('\n', wfp);
        fputc(c, wfp);
        fputc('\n', wfp);
    }
    else if (c == ';') {
        fputc(c, wfp);
        fputc('\n', wfp);
        fputc('\t', wfp);
    }
    else {
        fputc(c, wfp);
    }
}
