#include <stdio.h>
#include "otp.h"

int count_lines (FILE *fd)
{
    int lines = 0;
    char ch = 0;

    if (fd == NULL)
    {
        printf ("[ERROR] ... Invalid file descriptor...\n");
        return -1;
    }

    while (ch != EOF)
    {
        ch = fgetc (fd);
        if (ch == '\n') ++lines;
    }

    return lines;
}

int interpret_config_values (FILE *fd, int vals[], int lines)
{
    int i = 0;
    int j = 0;
    char ch = 0;
    int val = 0;

    if (fd == NULL)
    {
        printf ("[ERROR] ... Invalid file descriptor...\n");
        return -1;
    }

    while (!feof(fd))
    {
        fscanf (fd, "%d", &val);
        printf ("%d\n", val);
    }


//    for (i=0; i<lines; ++i)
//    {
//        while (ch != '\n')
//        {

//        }
//    }

    return 0;
}


