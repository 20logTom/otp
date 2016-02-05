#include <stdio.h>
#include <stdlib.h>
#include "otp.h"

int main(int argc, char *argv[])
{
	FILE *fdfile = 0;
	FILE *fdconfig = 0;
	FILE *fdkey = 0;
	int *configvalues = 0;
	int lines = 0;
	int error = 0;

	// check input parameters	
	if (argc < 5)
	{
	    printf ("Usage: ./otp encode|decode <filename> <config file> <private key>\n");
	    return -1;
	}
	
	// open files for reading
	fdfile = fopen (argv[2], "r");
	if (fdfile == NULL)
	{
	    printf ("[ERROR] ... Unable to open file for reading...\n");
	    return -1;
	}
	
	fdconfig = fopen (argv[3], "r");
	if (fdconfig == NULL)
	{
	    printf ("[ERROR] ... Unable to open config file for reading...\n");
	    return -1;
	}
	
	fdkey = fopen (argv[4], "r");
	if (fdkey == NULL)
	{
	    printf ("[ERROR] ... Unable to open file with private key for reading...\n");
	    return -1;
	}
	
	printf ("[INFO] ... Read three files...\n");
	
	// count lines in the read files
	lines = count_lines (fdfile);
	if (lines < 0)
	{
	    printf ("[ERROR] ... Unable to count lines in file...\n");
	    return -1;
	}
	
	configvalues = malloc (sizeof(int)*lines);
	if (configvalues == NULL)
	{
	    printf ("[ERROR] ... Unable to allocate memory for config values...\n");
	    return -1;
	}
	
	// interpret values
	error = interpret_config_values (fdfile, configvalues, lines);
	if (error != 0)
	{
	    printf ("[ERROR] ... Unable to interpret config values...\n");
	    return -1;
	}
	
	fclose (fdfile);
	if (fdfile == NULL)
	{
	    printf ("[ERROR] ... Unable to close file...\n");
	    return -1;
	}
	
	return 0;
}
