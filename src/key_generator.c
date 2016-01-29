#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int len = 0;
    int val = 0;
    int i = 0;
    FILE *fd = 0;

    if (argc < 2)
    {
        // printf ("Usage: ./%s <length of private key>\n", argv[0]);
        printf ("Usage: ./otp_keygen <length of private key>\n");
        return -1;
    }

    len = atoi (argv[1]);
    printf("Requested Length: %d\n", len);

    fd = fopen ("private_key.txt", "w+a");
    if (fd == NULL)
    {
        printf ("[ERROR] ... Unable to open file for writing...\n");
        return -1;
    }

    for (i=0; i<len; ++i)
    {
        val = (rand() % (126+1-33)) + 33; // (rand % (max+1-min)) + min
        printf ("val: %d\n", val);
        fprintf (fd, "%c", val);
    }
    return 0;
}

