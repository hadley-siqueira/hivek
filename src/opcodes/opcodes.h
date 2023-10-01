#ifndef EMULATOR_OPCODES_H
#define EMULATOR_OPCODES_H

#define OP_REG_REG 0
#define OP_ADDI 1

#define OP_LD 2
#define OP_LW 3
#define OP_LWU 4
#define OP_LH 5
#define OP_LHU 6
#define OP_LB 7
#define OP_LBU 8

#define OP_SD 9
#define OP_SW 10
#define OP_SH 11
#define OP_SB 12

#define OP_BEQ 13

#define F_ADD 0
#define F_SUB 1
#define F_AND 2
#define F_OR  3
#define F_XOR 4

#endif
