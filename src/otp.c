#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    FILE *fd = 0;
    int *config_vals = 0;
    int lines = 0;
    int err = 0;

    if (argc < 4)
    {
        printf ("Usage: ./otp <filename> <config file> <private key>\n");
        return -1;
    }

    fd = fopen (argv[2], "r");
    if (fd == NULL)
    {
        printf ("[ERROR] ... Unable to open file for reading...\n");
        return -1;
    }

    lines = count_lines (fd);
    if (lines < 0)
    {
        printf ("[ERROR] ... Unable to count lines in file...\n");
        return -1;
    }

    config_vals = malloc (sizeof(int)*lines);
    if (config_vals == NULL)
    {
        printf ("[ERROR] ... Unable to allocate memory for config values...\n");
        return -1;
    }

    // interpret values
    err = interpret_config_values (fd, config_vals, lines);
    if (err != 0)
    {
        printf ("[ERROR] ... Unable to interpret config values...\n");
        return -1;
    }

    fclose (fd);
    if (fd == NULL)
    {
        printf ("[ERROR] ... Unable to close file...\n");
        return -1;
    }

    return 0;
}

