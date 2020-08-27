#ifndef SWITCHERBOX_H
#define SWITCHERBOX_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define LPT1 0x378 /* Endereço base da porta paralela*/

// instruction struct
typedef struct {
    char   cmm;
    float  swt;
} instr;

void wait(const float *__secs);

int send_byte(unsigned char __BYTE);

int execute_script(FILE *__STREAM);

#endif
