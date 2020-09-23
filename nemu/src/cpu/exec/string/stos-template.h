#include "cpu/exec/template-start.h"

#define instr stos

make_helper(concat(stos_m_, SUFFIX)) {
    
    swaddr_write(REG(R_EDI),DATA_BYTE,REG(R_EAX));
	if (cpu.DF == 0) REG(R_EDI) += DATA_BYTE;
	else REG(R_EDI) -= DATA_BYTE;
	print_asm("stos");
    return 1;
}



#include "cpu/exec/template-end.h"