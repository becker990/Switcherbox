#ifndef BITAUX_H
#define BITAUX_H

#include "switcherbox.h"

unsigned char on(unsigned char bs, int swt);

unsigned char off(unsigned char bs, int swt);

unsigned char invert(unsigned char bs, int swt);

unsigned char rotate_left(unsigned char bs, int swt);

unsigned char rotate_right(unsigned char bs, int swt);

#endif
