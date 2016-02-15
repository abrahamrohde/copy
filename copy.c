#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#ifndef BUF_SIZE
#define BUF_SIZE 1
#endif


int main(int argc, char *argv[])
{
  FILE* readFile = fopen(argv[1], "r");
  FILE* writeFile = fopen(argv[2], "w");
  fseek(readFile, -1L, SEEK_END);
  long readFileCount  = (ftell(readFile)) + 1;
  while(readFileCount > 0)
    {
        char ch = fgetc(readFile);
        fputc(ch, writeFile);
        fseek(readFile, -2L, SEEK_CUR);
        readFileCount--;
    }
}