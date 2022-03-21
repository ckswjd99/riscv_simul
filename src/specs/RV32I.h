#ifndef SPEC_RV32I_H
#define SPEC_RV32I_H

/* REGISTERS */
#define REG_NUMBER 32
#define REG_XLEN 32


/* OPCODES & FUNCTS */

// OP_IMM: operations with immediates
#define OPCODE_OP_IMM 0x00

#define FUNCT3_ADDI 0x0
#define FUNCT3_SLTI 0x1
#define FUNCT3_SLTIU 0x2
#define FUNCT3_ANDI 0x3
#define FUNCT3_ORI 0x4
#define FUNCT3_XORI 0x5
#define FUNCT3_SLLI 0x6
#define FUNCT3_SRLI 0x7
#define FUNCT3_SRAI 0x8

#define FUNCT3_NOP FUNCT3_ADDI

// LUI: load upper immediate
#define OPCODE_LUI 0x01

// AUIPC: add upper immediate to pc
#define OPCODE_AUIPC 0x02

// OP: operations
#define OPCODE_OP 0x03

#define FUNCT3_ADD 0x0
#define FUNCT3_SLT 0x1
#define FUNCT3_SLTU 0x2
#define FUNCT3_AND 0x3
#define FUNCT3_OR 0x4
#define FUNCT3_XOR 0x5
#define FUNCT3_SLL 0x6
#define FUNCT3_SRL 0x7

#define FUNCT3_SUB 0x0
#define FUNCT3_SRA 0x1

// JAL: jump and link
#define OPCODE_JAL 0x04

// JALR: jump and link register
#define OPCODE_JALR 0x05

// BRANCH
#define OPCODE_BRANCH 0x06

#define FUNCT3_BEQ 0x0
#define FUNCT3_BNE 0x1
#define FUNCT3_BLT 0x2
#define FUNCT3_BLTU 0x3
#define FUNCT3_BGE 0x4
#define FUNCT3_BGEU 0x5

// LOAD: load from memory
#define OPCODE_LOAD 0x07

// STORE: store to memory
#define OPCODE_STORE 0x08

// MISC_MEM
#define OPCODE_MISC_MEM 0x09

#define FUNCT3_FENCE 0x0
#define FUNCT3_FENCE_I 0x1

// SYSTEM
#define OPCODE_SYSTEM 0x0A

#define FUNCT3_PRIV 0x0

#define FUNCT12_ECALL 0x0
#define FUNCT12_EBREAK 0x1

#endif