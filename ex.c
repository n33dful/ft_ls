#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void getFileCreationTime(char *filePath)
{
    struct stat attrib;
    stat(filePath, &attrib);
	time_t time = attrib.st_mtimespec.tv_sec;
    printf("The file was last modified at %ld\n", time);
}

int main(void)
{
	getFileCreationTime("a.out");
	return (0);
}
