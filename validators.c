#include "validators.h"

int is_valid_script(FILE *__STREAM){
    
    //status: done
    // the block below does a verification for each
    // instruction for validity and send error message if in case.
    // since its a physical implementation its better to
    // check the whole script before executing, to avoid stopping on the middle
    
    instr inst; 
    
    int c_insts=0;// todo:make count more than int instructions
    
    for (c_insts=0;;c_insts++) { 
        
        inst.cmm = '\0';
        inst.swt = -1;// -1 is switch missing flag, maybe think a better one?
        
        if (fscanf(__STREAM,"%c %f\n",&inst.cmm,&inst.swt) == -1) break;
        
                
        if (is_valid_instruction(inst) == 0){
            
            printf("The instruction number %d is incorrect, and so\n",c_insts+1);
            printf("the execution was cancelled to avoid imprecision.\n");
            exit(1);
        
        }
    
    
    }
    rewind(__STREAM);//rewinds before done
    return 1;
}

int is_valid_instruction(instr __inst){
    

    __inst.cmm = toupper(__inst.cmm);
	int flag;

    switch (__inst.cmm) {
        
        case 'L': break;
        
        case 'D': break;
        
        case 'I': break;
        
        case 'E': break;
        
        case 'R': break;
        
        case 'W': {	flag = 1;
					break;
				  }
			
        
        default: {
                    printf("Instruction code \"%c\" does not exists!\n",__inst.cmm);
                    return 0;
                 }
    }
    
    if ((__inst.swt < 0 || __inst.swt > 8) && flag == 0) {
        
        if (__inst.swt == -1){
            printf("Switch number missing!\n");
            return 0;
        }else{
            printf("Switch number %.f doesnt exist!\n",__inst.swt);
            return 0;
        }
        
    }
    
    return 1;    
}
