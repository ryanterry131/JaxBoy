// Copyright (C) 2017 Ryan Terry
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "../../common/Types.h"

#include <string>


// Colored immediate values
#define OP2        "\e[31m$%02X\e[0m"
#define OP4        "\e[31m$%04X\e[0m"

// Opcode definitions
struct Opcode
{
    std::string name;
    u8 length;
    u8 cycles;
    // For conditional branches
    u8 cycles_branch;
};

static const Opcode OPCODE_LOOKUP[256] = {
    {"NOP", 1, 4, 0},
    {"LD BC, " OP4, 3, 12, 0},
    {"LD (BC),A", 1, 8, 0},
    {"INC BC", 1, 8, 0},
    {"INC B", 1, 4, 0},
    {"DEC B", 1, 4, 0},
    {"LD B, " OP2, 2, 8, 0},
    {"RLCA", 1, 4, 0},
    {"LD (" OP4 "),SP", 3, 20, 0},
    {"ADD HL,BC", 1, 8, 0},
    {"LD A,(BC)", 1, 8, 0},
    {"DEC BC", 1, 8, 0},
    {"INC C", 1, 4, 0},
    {"DEC C", 1, 4, 0},
    {"LD C, " OP2, 2, 8, 0},
    {"RRCA", 1, 4, 0},

    {"STOP", 2, 4, 0},
    {"LD DE, " OP4, 3, 12, 0},
    {"LD (DE),A", 1, 8, 0},
    {"INC DE", 1, 8, 0},
    {"INC D", 1, 4, 0},
    {"DEC D", 1, 4, 0},
    {"LD D, " OP2, 2, 8, 0},
    {"RLA", 1, 4, 0},
    {"JR " OP2, 2, 12, 0},
    {"ADD HL,DE", 1, 8, 0},
    {"LD A,(DE)", 1, 8, 0},
    {"DEC DE", 1, 8, 0},
    {"INC E", 1, 4, 0},
    {"DEC E", 1, 4, 0},
    {"LD E, " OP2, 2, 8, 0},
    {"RRA", 1, 4, 0},

    {"JR NZ, " OP2, 2, 12, 0},
    {"LD HL, " OP4, 3, 12, 0},
    {"LD (HL+),A", 1, 8, 0},
    {"INC HL", 1, 8, 0},
    {"INC H", 1, 4, 0},
    {"DEC H", 1, 4, 0},
    {"LD H, " OP2, 2, 8, 0},
    {"DAA", 1, 4, 0},
    {"JR Z, " OP2, 2, 12, 0},
    {"ADD HL,HL", 1, 8, 0},
    {"LD A,(HL+)", 1, 8, 0},
    {"DEC HL", 1, 8, 0},
    {"INC L", 1, 4, 0},
    {"DEC L", 1, 4, 0},
    {"LD L, " OP2, 2, 8, 0},
    {"CPL", 1, 4, 0},

    {"JR NC, " OP2, 2, 12, 0},
    {"LD SP, " OP4, 3, 12, 0},
    {"LD (HL-),A", 1, 8, 0},
    {"INC SP", 1, 8, 0},
    {"INC (HL)", 1, 12, 0},
    {"DEC (HL)", 1, 12, 0},
    {"LD (HL), " OP2, 2, 12, 0},
    {"SCF", 1, 4, 0},
    {"JR C, " OP2, 2, 12, 0},
    {"ADD HL,SP", 1, 8, 0},
    {"LD A,(HL-)", 1, 8, 0},
    {"DEC SP", 1, 8, 0},
    {"INC A", 1, 4, 0},
    {"DEC A", 1, 4, 0},
    {"LD A, " OP2, 2, 8, 0},
    {"CCF", 1, 4, 0},

    {"LD B,B", 1, 4, 0},
    {"LD B,C", 1, 4, 0},
    {"LD B,D", 1, 4, 0},
    {"LD B,E", 1, 4, 0},
    {"LD B,H", 1, 4, 0},
    {"LD B,L", 1, 4, 0},
    {"LD B,(HL)", 1, 8, 0},
    {"LD B,A", 1, 4, 0},
    {"LD C,B", 1, 4, 0},
    {"LD C,C", 1, 4, 0},
    {"LD C,D", 1, 4, 0},
    {"LD C,E", 1, 4, 0},
    {"LD C,H", 1, 4, 0},
    {"LD C,L", 1, 4, 0},
    {"LD C,(HL)", 1, 8, 0},
    {"LD C,A", 1, 4, 0},

    {"LD D,B", 1, 4, 0},
    {"LD D,C", 1, 4, 0},
    {"LD D,D", 1, 4, 0},
    {"LD D,E", 1, 4, 0},
    {"LD D,H", 1, 4, 0},
    {"LD D,L", 1, 4, 0},
    {"LD D,(HL)", 1, 8, 0},
    {"LD D,A", 1, 4, 0},
    {"LD E,B", 1, 4, 0},
    {"LD E,C", 1, 4, 0},
    {"LD E,D", 1, 4, 0},
    {"LD E,E", 1, 4, 0},
    {"LD E,H", 1, 4, 0},
    {"LD E,L", 1, 4, 0},
    {"LD E,(HL)", 1, 8, 0},
    {"LD E,A", 1, 4, 0},

    {"LD H,B", 1, 4, 0},
    {"LD H,C", 1, 4, 0},
    {"LD H,D", 1, 4, 0},
    {"LD H,E", 1, 4, 0},
    {"LD H,H", 1, 4, 0},
    {"LD H,L", 1, 4, 0},
    {"LD H,(HL)", 1, 8, 0},
    {"LD H,A", 1, 4, 0},
    {"LD L,B", 1, 4, 0},
    {"LD L,C", 1, 4, 0},
    {"LD L,D", 1, 4, 0},
    {"LD L,E", 1, 4, 0},
    {"LD L,H", 1, 4, 0},
    {"LD L,L", 1, 4, 0},
    {"LD L,(HL)", 1, 8, 0},
    {"LD L,A", 1, 4, 0},

    {"LD (HL),B", 1, 8, 0},
    {"LD (HL),C", 1, 8, 0},
    {"LD (HL),D", 1, 8, 0},
    {"LD (HL),E", 1, 8, 0},
    {"LD (HL),H", 1, 8, 0},
    {"LD (HL),L", 1, 8, 0},
    {"HALT", 1, 4, 0},
    {"LD (HL),A", 1, 8, 0},
    {"LD A,B", 1, 4, 0},
    {"LD A,C", 1, 4, 0},
    {"LD A,D", 1, 4, 0},
    {"LD A,E", 1, 4, 0},
    {"LD A,H", 1, 4, 0},
    {"LD A,L", 1, 4, 0},
    {"LD A,(HL)", 1, 8, 0},
    {"LD A,A", 1, 4, 0},

    {"ADD A,B", 1, 4, 0},
    {"ADD A,C", 1, 4, 0},
    {"ADD A,D", 1, 4, 0},
    {"ADD A,E", 1, 4, 0},
    {"ADD A,H", 1, 4, 0},
    {"ADD A,L", 1, 4, 0},
    {"ADD A,(HL)", 1, 8, 0},
    {"ADD A,A", 1, 4, 0},
    {"ADC A,B", 1, 4, 0},
    {"ADC A,C", 1, 4, 0},
    {"ADC A,D", 1, 4, 0},
    {"ADC A,E", 1, 4, 0},
    {"ADC A,H", 1, 4, 0},
    {"ADC A,L", 1, 4, 0},
    {"ADC A,(HL)", 1, 8, 0},
    {"ADC A,A", 1, 4, 0},

    {"SUB B", 1, 4, 0},
    {"SUB C", 1, 4, 0},
    {"SUB D", 1, 4, 0},
    {"SUB E", 1, 4, 0},
    {"SUB H", 1, 4, 0},
    {"SUB L", 1, 4, 0},
    {"SUB (HL)", 1, 8, 0},
    {"SUB A", 1, 4, 0},
    {"SBC A,B", 1, 4, 0},
    {"SBC A,C", 1, 4, 0},
    {"SBC A,D", 1, 4, 0},
    {"SBC A,E", 1, 4, 0},
    {"SBC A,H", 1, 4, 0},
    {"SBC A,L", 1, 4, 0},
    {"SBC A,(HL)", 1, 8, 0},
    {"SBC A,A", 1, 4, 0},

    {"AND B", 1, 4, 0},
    {"AND C", 1, 4, 0},
    {"AND D", 1, 4, 0},
    {"AND E", 1, 4, 0},
    {"AND H", 1, 4, 0},
    {"AND L", 1, 4, 0},
    {"AND (HL)", 1, 8, 0},
    {"AND A", 1, 4, 0},
    {"XOR B", 1, 4, 0},
    {"XOR C", 1, 4, 0},
    {"XOR D", 1, 4, 0},
    {"XOR E", 1, 4, 0},
    {"XOR H", 1, 4, 0},
    {"XOR L", 1, 4, 0},
    {"XOR (HL)", 1, 8, 0},
    {"XOR A", 1, 4, 0},

    {"OR B", 1, 4, 0},
    {"OR C", 1, 4, 0},
    {"OR D", 1, 4, 0},
    {"OR E", 1, 4, 0},
    {"OR H", 1, 4, 0},
    {"OR L", 1, 4, 0},
    {"OR (HL)", 1, 8, 0},
    {"OR A", 1, 4, 0},
    {"CP B", 1, 4, 0},
    {"CP C", 1, 4, 0},
    {"CP D", 1, 4, 0},
    {"CP E", 1, 4, 0},
    {"CP H", 1, 4, 0},
    {"CP L", 1, 4, 0},
    {"CP (HL)", 1, 8, 0},
    {"CP A", 1, 4, 0},

    {"RET NZ", 1, 20, 0},
    {"POP BC", 1, 12, 0},
    {"JP NZ, " OP4, 3, 16, 0},
    {"JP " OP4, 3, 16, 0},
    {"CALL NZ, " OP4, 3, 24, 0},
    {"PUSH BC", 1, 16, 0},
    {"ADD A, " OP2, 2, 8, 0},
    {"RST 00H", 1, 16, 0},
    {"RET Z", 1, 20, 0},
    {"RET", 1, 16, 0},
    {"JP Z, " OP4, 3, 16, 0},
    {"CB EXT", 1, 4, 0},
    {"CALL Z, " OP4, 3, 24, 0},
    {"CALL " OP4, 3, 24, 0},
    {"ADC A, " OP2, 2, 8, 0},
    {"RST 08H", 1, 16, 0},

    {"RET NC", 1, 20, 0},
    {"POP DE", 1, 12, 0},
    {"JP NC, " OP4, 3, 16, 0},
    {"UNDEFINED", 0, 0, 0},
    {"CALL NC, " OP4, 3, 24, 0},
    {"PUSH DE", 1, 16, 0},
    {"SUB " OP2, 2, 8, 0},
    {"RST 10H", 1, 16, 0},
    {"RET C", 1, 20, 0},
    {"RETI", 1, 16, 0},
    {"JP C, " OP4, 3, 16, 0},
    {"UNDEFINED", 0, 0, 0},
    {"CALL C, " OP4, 3, 24, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SBC A, " OP2, 2, 8, 0},
    {"RST 18H", 1, 16, 0},

    {"LD (FF+" OP2 "),A", 2, 12, 0},
    {"POP HL", 1, 12, 0},
    {"LD (FF00h+C),A", 1, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"PUSH HL", 1, 16, 0},
    {"AND " OP2, 2, 8, 0},
    {"RST 20H", 1, 16, 0},
    {"ADD SP, " OP2, 2, 16, 0},
    {"JP HL", 1, 4, 0},
    {"LD (" OP4 "),A", 3, 16, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"XOR " OP2, 2, 8, 0},
    {"RST 28H", 1, 16, 0},

    {"LD A,(FF+" OP2 ")", 2, 12, 0},
    {"POP AF", 1, 12, 0},
    {"LD A,(C)", 2, 8, 0},
    {"DI", 1, 4, 0},
    {"UNDEFINED", 0, 0, 0},
    {"PUSH AF", 1, 16, 0},
    {"OR " OP2, 2, 8, 0},
    {"RST 30H", 1, 16, 0},
    {"LD HL,SP+" OP2, 2, 12, 0},
    {"LD SP,HL", 1, 8, 0},
    {"LD A,(" OP4 ")", 3, 16, 0},
    {"EI", 1, 4, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"CP " OP2, 2, 8, 0},
    {"RST 38H", 1, 16, 0}
};

static const Opcode CB_OPCODE_LOOKUP[256] = {
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"RL C", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"RR C", 2, 8, 0},
    {"RR D", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SLA A", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SWAP A", 2, 8, 0},
    {"SRL B", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SRL A", 2, 8, 0},

    {"BIT 0,B", 2, 8, 0},
    {"BIT 0,C", 2, 8, 0},
    {"BIT 0,D", 2, 8, 0},
    {"BIT 0,E", 2, 8, 0},
    {"BIT 0,H", 2, 8, 0},
    {"BIT 0,L", 2, 8, 0},
    {"BIT 0,(HL)", 2, 8, 0},
    {"BIT 0,A", 2, 8, 0},
    {"BIT 1,B", 2, 8, 0},
    {"BIT 1,C", 2, 8, 0},
    {"BIT 1,D", 2, 8, 0},
    {"BIT 1,E", 2, 8, 0},
    {"BIT 1,H", 2, 8, 0},
    {"BIT 1,L", 2, 8, 0},
    {"BIT 1,(HL)", 2, 8, 0},
    {"BIT 1,A", 2, 8, 0},

    {"BIT 2,B", 2, 8, 0},
    {"BIT 2,C", 2, 8, 0},
    {"BIT 2,D", 2, 8, 0},
    {"BIT 2,E", 2, 8, 0},
    {"BIT 2,H", 2, 8, 0},
    {"BIT 2,L", 2, 8, 0},
    {"BIT 2,(HL)", 2, 8, 0},
    {"BIT 2,A", 2, 8, 0},
    {"BIT 3,B", 2, 8, 0},
    {"BIT 3,C", 2, 8, 0},
    {"BIT 3,D", 2, 8, 0},
    {"BIT 3,E", 2, 8, 0},
    {"BIT 3,H", 2, 8, 0},
    {"BIT 3,L", 2, 8, 0},
    {"BIT 3,(HL)", 2, 8, 0},
    {"BIT 3,A", 2, 8, 0},

    {"BIT 4,B", 2, 8, 0},
    {"BIT 4,C", 2, 8, 0},
    {"BIT 4,D", 2, 8, 0},
    {"BIT 4,E", 2, 8, 0},
    {"BIT 4,H", 2, 8, 0},
    {"BIT 4,L", 2, 8, 0},
    {"BIT 4,(HL)", 2, 8, 0},
    {"BIT 4,A", 2, 8, 0},
    {"BIT 5,B", 2, 8, 0},
    {"BIT 5,C", 2, 8, 0},
    {"BIT 5,D", 2, 8, 0},
    {"BIT 5,E", 2, 8, 0},
    {"BIT 5,H", 2, 8, 0},
    {"BIT 5,L", 2, 8, 0},
    {"BIT 5,(HL)", 2, 8, 0},
    {"BIT 5,A", 2, 8, 0},

    {"BIT 6,B", 2, 8, 0},
    {"BIT 6,C", 2, 8, 0},
    {"BIT 6,D", 2, 8, 0},
    {"BIT 6,E", 2, 8, 0},
    {"BIT 6,H", 2, 8, 0},
    {"BIT 6,L", 2, 8, 0},
    {"BIT 6,(HL)", 2, 8, 0},
    {"BIT 6,A", 2, 8, 0},
    {"BIT 7,B", 2, 8, 0},
    {"BIT 7,C", 2, 8, 0},
    {"BIT 7,D", 2, 8, 0},
    {"BIT 7,E", 2, 8, 0},
    {"BIT 7,H", 2, 8, 0},
    {"BIT 7,L", 2, 8, 0},
    {"BIT 7,(HL)", 2, 8, 0},
    {"BIT 7,A", 2, 8, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"RES 0,A", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"RES 7,(HL)", 2, 16, 0},
    {"RES 7,A", 2, 8, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SET 0,A", 2, 8, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},

    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"UNDEFINED", 0, 0, 0},
    {"SET 7,A", 2, 8, 0}
};
