#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int get_output_filename (char *outfile, char const *path, char const *prefix, char const *ext)
{
	int error = 0;
	char timestamp[20];
	time_t totalseconds = time(NULL);
	struct tm *local = localtime (&totalseconds);
	char month[3];
	char day[3];
	char hour[3];
	char minute[3];
	char second[3];

	// determine timestamp variables
	error = (local->tm_mon+1 < 10) ? sprintf (month, "0%d", local->tm_mon+1) : sprintf (month, "%d", local->tm_mon+1);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the month...\n");
		return -1;
	}
	
	error = (local->tm_mday < 10) ? sprintf (day, "0%d", local->tm_mday) : sprintf (day, "%d", local->tm_mday);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the day...\n");
		return -1;
	}
	
	error = (local->tm_hour < 10) ? sprintf (hour, "0%d", local->tm_hour) : sprintf (hour, "%d", local->tm_hour);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the hour...\n");
		return -1;
	}
	
	error = (local->tm_min < 10) ? sprintf (minute, "0%d", local->tm_min) : sprintf (minute, "%d", local->tm_min);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the minute...\n");
		return -1;
	}
	
	error = (local->tm_sec < 10) ? sprintf (second, "0%d", local->tm_sec) : sprintf (second, "%d", local->tm_sec);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the second...\n");
		return -1;
	}

	// determine entire timestamp string
	error = sprintf (timestamp, "%d_%s_%s_%s_%s_%s", local->tm_year+1900, month, day, hour, minute, second);
	if (error < 0)
	{
		printf ("[ERROR] ... Unable to determine string variable for the timestamp...\n");
		return -1;
	}
	
	// determine output filename with timestamp
	error = sprintf (outfile, "%s/%s_%s.%s", path, prefix, timestamp, ext);

	return (error < 0) ? -1 : error;
}
