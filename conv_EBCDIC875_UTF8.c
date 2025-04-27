/*Reads from a file with EBCDIC encoding (IBM CCSID 875) from IFS
  and creates a new copy of the file converted to UTF-8 encoding.
  Some characters are not used and some are exactly the same as in
  UTF-8. They appear in the program just for reference. */


/* What happens when read or write fail?? */

/* Read from a file with EBCDIC encoding, CCSID = 875 and create a new copy file
converting to UTF-8 encoding */


#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "EBCDIC875_UTF8.h"
#include <sys/time.h>



double get_time_in_seconds() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec + (time.tv_usec / 1e6);
}

void methodA(char *inputFilePath, char *outputFilePath)
{
	int inputFile, outputFile; // j; //bytesWritten, bytesToWrite;
    unsigned char inputChar;
    //unsigned char outputCharBuf[3];
    //j = 0;
    if( (inputFile  = open(inputFilePath, O_RDONLY)) == -1)   							return;
    if( (outputFile = open(outputFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)  return;

    while (read(inputFile, &inputChar, 1) > 0)
    {
		for (int k=0; k < EBCDIC875_UTF8[inputChar].numberOfBytes; k++)
			write(outputFile, &(EBCDIC875_UTF8[inputChar].bytes[k]), 1);
		
		
		
	/*	
			outputCharBuf[j++] = EBCDIC875_UTF8[inputChar].bytes[k];
        bytesToWrite = j;
        j=0;
        while(bytesToWrite > 0)
        {
            bytesWritten = write(outputFile, &outputCharBuf[j], bytesToWrite);
            bytesToWrite -= bytesWritten;
            j += bytesWritten;
        }
		*/
    }
    close(inputFile);
    close(outputFile);
}


void methodB(char *inputFilePath, char *outputFilePath)
{
	int inputFile, outputFile, i, j, bytesToWrite;
	ssize_t bytesRead, bytesWritten;
    unsigned char inputChar;
    unsigned char inputCharBuf[16384], outputCharBuf[32768];
    //unsigned char inputCharBuf[32768], outputCharBuf[65536];
    //unsigned char inputCharBuf[32768], outputCharBuf[65536];
    bytesRead = bytesWritten = 0;
    if( (inputFile  = open(inputFilePath, O_RDONLY)) == -1)   							return;
    if( (outputFile = open(outputFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)  return;

    while ( (bytesRead = read(inputFile, inputCharBuf, 16384)) > 0)
    {
        j=0;
        for (i=0; i < bytesRead; ++i)
        {
            inputChar = inputCharBuf[i];
			for (int k=0; k < EBCDIC875_UTF8[inputChar].numberOfBytes; k++) {
				outputCharBuf[j++] = EBCDIC875_UTF8[inputChar].bytes[k];
			}
        }
        bytesToWrite = j;
        j=0;
        while(bytesToWrite > 0)
        {
            bytesWritten = write(outputFile, &outputCharBuf[j], bytesToWrite);
            bytesToWrite -= bytesWritten;
            j += bytesWritten;
        }
    }
    close(inputFile);
    close(outputFile);
}


void methodC(char *inputFilePath, char *outputFilePath)
{
    unsigned char inputChar;
	
	FILE *inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) return;
	
	FILE *outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) return;

	
    while (fread(&inputChar, 1, 1, inputFile) == 1)
    {
		for (int k=0; k < EBCDIC875_UTF8[inputChar].numberOfBytes; k++)
			fwrite(&(EBCDIC875_UTF8[inputChar].bytes[k]), 1, 1, outputFile);
	}
	
    fclose(inputFile);
    fclose(outputFile);
}


void methodD(char *inputFilePath, char *outputFilePath)
{
	unsigned char inputChar, inputCharBuf[16384];
	ssize_t bytesRead;
	int i;
	
	FILE *inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) return;
	
	FILE *outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) return;

		
    while ( (bytesRead = fread(&inputCharBuf, 1, 16384, inputFile)) > 1)
    {
        for (i=0; i < bytesRead; ++i)
        {
            inputChar = inputCharBuf[i];
			for (int k=0; k < EBCDIC875_UTF8[inputChar].numberOfBytes; k++) {
				fwrite(&(EBCDIC875_UTF8[inputChar].bytes[k]), 1, 1, outputFile);
			}
        }
	}
	
    fclose(inputFile);
    fclose(outputFile);
}


void methodE(char *inputFilePath, char *outputFilePath)
{
	unsigned char inputChar, inputCharBuf[16384], outputCharBuf[32768];
	ssize_t bytesRead, bytesWritten;
	int i, j, bytesToWrite;
	
	FILE *inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) return;
	
	FILE *outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) return;

		
    while ( (bytesRead = fread(&inputCharBuf, 1, 16384, inputFile)) > 1)
    {
		j=0;
        for (i=0; i < bytesRead; ++i)
        {
            inputChar = inputCharBuf[i];
			for (int k=0; k < EBCDIC875_UTF8[inputChar].numberOfBytes; k++) {
				outputCharBuf[j++] = EBCDIC875_UTF8[inputChar].bytes[k];
			}
        }
		
        bytesToWrite = j;
        j=0;
        while(bytesToWrite > 0)
        {
            bytesWritten = fwrite(&(outputCharBuf[j]), 1, bytesToWrite, outputFile);
            bytesToWrite -= bytesWritten;
            j += bytesWritten;
        }
	}		
    fclose(inputFile);
    fclose(outputFile);
}


int main(int argc, char **argv)
{
	char *inputFilePath, *outputFilePath;
	inputFilePath = outputFilePath = NULL;
    int n1 = strlen(*(argv+1));
    int n2 = strlen(*(argv+2));
    inputFilePath  = malloc(n1+1 * sizeof(char));
    outputFilePath = malloc(n2+1 * sizeof(char));
    memset(inputFilePath,  '\0', n1+1);
    memset(outputFilePath, '\0', n2+1);
    strncpy(inputFilePath,  *(argv+1), n1); 
    strncpy(outputFilePath, *(argv+2), n2);
	
	char version = *(argv[3]);
	double start, end;
	switch(version)
	{
		case 'A':		//use write
			printf("Use write function with no custom buffering\n");
			start = get_time_in_seconds();
			methodA(inputFilePath, outputFilePath);
			end = get_time_in_seconds();
			printf("Time for write(): %.6f seconds\n", end - start);
			break;
			
		case 'B':		//use write with custom buffering
			printf("Use write function with custom buffering\n");
			start = get_time_in_seconds();
			methodB(inputFilePath, outputFilePath);
			end = get_time_in_seconds();
			printf("Time for write(): %.6f seconds\n", end - start);
			break;
			
		case 'C':		//use ????
			printf("???\n");
			start = get_time_in_seconds();
			methodC(inputFilePath, outputFilePath);
			end = get_time_in_seconds();
			printf("Time for write(): %.6f seconds\n", end - start);
			break;
			
		case 'D':		//use ???
			printf("???\n");
			start = get_time_in_seconds();
			methodD(inputFilePath, outputFilePath);
			end = get_time_in_seconds();
			printf("Time for write(): %.6f seconds\n", end - start);
			break;
		
		case 'E':		//use ??
			printf("???\n");
			start = get_time_in_seconds();
			methodD(inputFilePath, outputFilePath);
			end = get_time_in_seconds();
			printf("Time for write(): %.6f seconds\n", end - start);
			break;
			
		default:
			printf("Please provide a valid method. Accepted values are A,B,C,D,E\n");
	}
	return 0;
}

/*
use fwrite or write?
write to a buf first or write directly to the file.
does fwrite or write use buffering and should I use that?

*/