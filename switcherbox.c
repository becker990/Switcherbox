#include "switcherbox.h"
#include "bitaux.h"
#include "validators.h"

int main(int argc, char** argv)
{
    int cnt;
    FILE *fp = NULL;
    

    while ( (fp = fopen(argv[1],"r")) == NULL) {

        printf("Type the name of the script to execute.\n");
        printf("Or type 'interactive' for interactive execution.\n");
        fgets(arq_name,32,stdin);
        for (cnt=0; cnt<32; cnt++){// quick n ugly hack
            if (arq_name[cnt] == '\n')
                arq_name[cnt] = '\0';
        }

        if (!strcmp(arq_name,"interactive")){

            printf("Entering interactive operation...NOT IMPLEMENTED YET");
            //well, have to do it yet hehe
            // i think will use a infinite loop with break and special words

        }
        system("clear");//*nix only... make it portable

    }


    if ( is_valid_script(fp) == 1){
        //like seems ok send to execute

        if (execute_script(fp) == 0){
            printf("Script executed with success!\n");
        }

    }

    fclose(fp);

    return 0;
}



int execute_script(FILE *__STREAM){

    // since everything seems ok, its time to execute the script

    instr __what;
    int c_insts;// todo:make count more than int instructions
    unsigned char bs = 0x00;

    // for each instruction calls the handler
    for (c_insts=0;;c_insts++) {

        __what.cmm = '\0';//resets the vars
        __what.swt = -1;

        if (fscanf(__STREAM,"%c %f\n",&__what.cmm,&__what.swt) == -1) break;

        __what.cmm = toupper(__what.cmm);

        printf("%c %.f\n",__what.cmm,__what.swt);

        switch (__what.cmm) {

            //on
            case 'L': {
                            send_byte(on(bs, __what.swt));
                            bs = on(bs, __what.swt);
                            break;
                      }

            //off
            case 'D': {
                            send_byte(off(bs, __what.swt));
                            bs = off(bs, __what.swt);
                            break;
                      }

            //invert
            case 'I': {
                            send_byte(invert(bs, __what.swt));
                            bs = invert(bs, __what.swt);
                            break;
                      }

            //rotate left
            case 'E': {
                            send_byte(rotate_left(bs, __what.swt));
                            bs = rotate_left(bs, __what.swt);
                            break;
                      }

            //rotate right
            case 'R': {
                            send_byte(rotate_right(bs, __what.swt));
                            bs = rotate_right(bs,__what.swt);
                            break;
                      }

            //wait secs, the whole reason to bring float switch
            case 'W': { wait(&__what.swt); break;}

            default: {
                        printf("Instruction code \"%c\" does not exists!\n",__what.cmm);
                        return 0;
                    }

        }//switch end

    }

    rewind(__STREAM);//rewinds before done

    return 0;
}



void wait(const float *__secs){

    int        i;
    float      k;
    useconds_t usecs;

    i = (int)*__secs;

    k = (float)i - *__secs;// x.x'
    k = k * (-1);
    usecs = k * 1000000;

    //printf("oo%d    %d\n\n",i,usecs);


    printf("waiting %f\n",*__secs);
    sleep(i);//sleep integer part

    usleep(usecs);// sleep the usecs part


}

int send_byte(unsigned char __BYTE){

    //todo: make this window$ portable

    if (ioperm(LPT1,1,1)){
        printf("It was not possible to open the port, run as root!\n");
        exit(1);
    }

    outb(__BYTE, LPT1);

    printf("byte sent: 0x%X\n",__BYTE);


    return 0;
}


