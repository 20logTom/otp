#ifndef OTP_H
#define OTP_H

#include <stdlib.h>

int encode (FILE *fdsrc, FILE *fdtgt, FILE *fdcfg, FILE *fdkey);
int decode (FILE *fdsrc, FILE *fdtgt, FILE *fdcfg, FILE *fdkey);

#endif // OTP_H
