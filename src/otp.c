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
	// int i = 0;
	// int j = 0;
	// char ch = 0;
	int val = 0;

	printf ("[INFO] ... entering function \"interpret_config_values()\"...\n");

	if (fd == NULL)
	{
		printf ("[ERROR] ... Invalid file descriptor...\n");
		return -1;
	}
	
	if (feof(fd)) printf ("[INFO] ... end of file...\n");
	else printf("[INFO] ... not end of file...\n");

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


int encode (FILE *fdsrc, FILE *fdtgt, FILE *fdcfg, FILE *fdkey)
{
	int *configvalues = 0;
	int lines = 0;
	int error = 0;

	printf ("[INFO] ... Start encoding...\n");

	// count lines in the read files
	lines = count_lines (fdsrc);
	if (lines < 0)
	{
	    printf ("[ERROR] ... Unable to count lines in file...\n");
	    return -1;
	}

	printf ("[INFO] ... Read %d lines in source file...\n", lines);
	
	configvalues = malloc (sizeof(int)*lines);
	if (configvalues == NULL)
	{
	    printf ("[ERROR] ... Unable to allocate memory for config values...\n");
	    return -1;
	}

	// interpret values
	error = interpret_config_values (fdsrc, configvalues, lines);
	if (error != 0)
	{
	    printf ("[ERROR] ... Unable to interpret config values...\n");
	    return -1;
	}
	
	return 0;
}

int decode (FILE *fdsrc, FILE *fdtgt, FILE *fdcfg, FILE *fdkey)
{
	printf ("[INFO] ... Start decoding...\n");

	return 0;
}

