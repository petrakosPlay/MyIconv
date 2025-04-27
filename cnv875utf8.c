/*
  Reads from a file with EBCDIC encoding (IBM CCSID 875) from IFS
  and creates a new copy of the file converted to UTF-8 encoding.
*/

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "EBCDIC875_UTF8.h"


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
	
	int inputFile, outputFile, i, j, bytesToWrite;
	ssize_t bytesRead, bytesWritten;
    unsigned char inputCharBuf[16384], outputCharBuf[32768];
    bytesRead = bytesWritten = 0;
    
	if( (inputFile  = open(inputFilePath, O_RDONLY)) == -1)   							return 0;
    if( (outputFile = open(outputFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)  return 0;

    while ( (bytesRead = read(inputFile, inputCharBuf, 16384)) > 0)
    {
        j=0;
        for (i=0; i < bytesRead; ++i)
        {
			for (int k=0; k < EBCDIC875_UTF8[inputCharBuf[i]].numberOfBytes; k++) {
				outputCharBuf[j++] = EBCDIC875_UTF8[inputCharBuf[i]].bytes[k];
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

	return 0;
}
