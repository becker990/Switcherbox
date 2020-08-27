#include "bitaux.h"

// these are the great facilitators, and the whole project goal
// this is binary magick, do not touch o.o
unsigned char on(unsigned char bs, int swt){
    
    if (swt == 0){
        return 0xff;
    }else{        
        return(bs | (1 << (swt -1)));
    }
}

unsigned char off(unsigned char bs, int swt){
    if (swt == 0){
        return 0x00;
    }else{		        
        return (bs & (~(1 << (swt -1))));
    }    
}

unsigned char invert(unsigned char bs, int swt){
    
    if (swt == 0){
        return ~(bs);
    }else{
        
        if ((bs & (1 << (swt -1))) != 0){
            return off(bs,swt);
        }else{
            return on(bs,swt);
        }

    }
}

unsigned char rotate_left(unsigned char bs, int swt){
    if (swt ==0) {
        return bs << 1;
    }else{
        if ((bs & (1 << (swt -1))) != 0){
            return off((on(bs,swt-1)),swt);            
        }else{
            return bs;
        }
    }
}

unsigned char rotate_right(unsigned char bs, int swt){
    if (swt == 0){
        return bs >> 1;
    }else{
        if ((bs & (1 << (swt -1))) != 0){
           return off((on(bs,swt+1)),swt);
        }else{
            return bs;
        }
    }
}
