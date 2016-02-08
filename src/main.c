#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "otp.h"
#include "utils.h"

int main(int argc, char *argv[])
{
	FILE *fdsrc = 0;
	FILE *fdtgt = 0;
	FILE *fdcfg = 0;
	FILE *fdkey = 0;
	int error = 0;
	char outfile[40];

	// check input parameters	
	if (argc < 5)
	{
	    printf ("Usage: ./otp encode|decode <source file> <config file> <private key>\n");
	    return -1;
	}
	
	// open files for reading
	fdsrc = fopen (argv[2], "r");
	if (fdsrc == NULL)
	{
	    printf ("[ERROR] ... Unable to open source file for reading...\n");
	    return -1;
	}
	
	fdcfg = fopen (argv[3], "r");
	if (fdcfg == NULL)
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
	
	// determine requested operation
	if (!strcmp(argv[1], "encode"))
	{
		// determine name for output file
		error = get_output_filename (outfile, "enc", "encrypted", "txt");
		if (error < 0)
		{
			printf ("[ERROR] ... Unable to determine output filename for encrypted file...\n");
			return -1;
		}
		
		// open target file for writing
		fdtgt = fopen (outfile, "w+a");
		if (fdtgt == NULL)
		{
		    printf ("[ERROR] ... Unable to open target file for writing...\n");
		    return -1;
		}
	
		error = encode (fdsrc, fdtgt, fdcfg, fdkey);
		if (error < 0)
		{
			printf ("[ERROR] ... Encryption failed...\n");
			return -1;
		}
	}
	else if (!strcmp(argv[1], "decode"))
	{
		// determine name for output file
		error = get_output_filename (outfile, "dec", "decrypted", "txt");
		if (error < 0)
		{
			printf ("[ERROR] ... Unable to determine output filename for decrypted file...\n");
			return -1;
		}
		
		// open target file for writing
		fdtgt = fopen (outfile, "w+a");
		if (fdtgt == NULL)
		{
		    printf ("[ERROR] ... Unable to open target file for writing...\n");
		    return -1;
		}
	
		error = decode (fdsrc, fdtgt, fdcfg, fdkey);
		if (error < 0)
		{
			printf ("[ERROR] ... Decryption failed...\n");
			return -1;
		}
	}
	else
	{
		printf ("[ERROR] ... Invalid operation...\n");
		return -1;
	}
	
	// close all files
	fclose (fdsrc);
	if (fdsrc == NULL)
	{
	    printf ("[ERROR] ... Unable to close source file...\n");
	    return -1;
	}
	
	fclose (fdcfg);
	if (fdcfg == NULL)
	{
	    printf ("[ERROR] ... Unable to close config file...\n");
	    return -1;
	}
	
	fclose (fdkey);
	if (fdkey == NULL)
	{
	    printf ("[ERROR] ... Unable to close file with private key...\n");
	    return -1;
	}
	
	fclose (fdtgt);
	if (fdtgt == NULL)
	{
	    printf ("[ERROR] ... Unable to close target file...\n");
	    return -1;
	}
	
	return 0;
}
