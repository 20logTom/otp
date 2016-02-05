#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
	int len = 0;
	int val = 0;
	int i = 0;
	FILE *fd = 0;
	char outfile[40];
	int error = 0;

	if (argc < 2)
	{
		// printf ("Usage: ./%s <length of private key>\n", argv[0]);
		printf ("Usage: ./keygen <length of private key>\n");
		return -1;
	}
	
	len = atoi (argv[1]);
	printf("Requested Length: %d\n", len);

	// determine output filename
	error = get_output_filename (outfile, "key", "private_key", "txt");
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine output filename for private key...\n");
		return -1;
	}
	
	fd = fopen (outfile, "w+a");
	if (fd == NULL)
	{
		printf ("[ERROR] ... Unable to open file for writing private key...\n");
		return -1;
	}
	
	for (i=0; i<len; ++i)
	{
		val = (rand() % (126+1-33)) + 33; // (rand % (max+1-min)) + min
		printf ("val: %d\n", val);
		fprintf (fd, "%c", val);
	}

	fclose (fd);
	if (fd == NULL)
	{
		printf ("[ERROR] ... Unable to close file...\n");
		return -1;
	}
	
	return 0;
}

