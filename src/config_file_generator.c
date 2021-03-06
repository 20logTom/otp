#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main(int argc, char *argv[])
{
	int max = 0;
	int val = 0;
	int i = 0;
	FILE *fd = 0;
	char outfile[40];
	int error = 0;

	if (argc < 2)
	{
		printf ("Usage: %s <number of config params>\n", argv[0]);
		return -1;
	}
	
	max = atoi (argv[1]);
	printf("Requested Number: %d\n", max);
	
	// determine output filename
	error = get_output_filename (outfile, "cfg", "config", "txt");
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine output filename for private key...\n");
		return -1;
	}
	
	fd = fopen (outfile, "w+a");
	if (fd == NULL)
	{
		printf ("[ERROR] ... Unable to open file for writing...\n");
		return -1;
	}
	
	srand (time(NULL));
	
	for (i=0; i<max; ++i)
	{
		val = (rand() % (1000+1-10)) + 10; // (rand % (max+1-min)) + min
		// printf ("val: %d\n", val);
		fprintf (fd, "%d\n", val);
	}
	
	fclose (fd);
	if (fd == NULL)
	{
		printf ("[ERROR] ... Unable to close file...\n");
		return -1;
	}
	
	return 0;
}

