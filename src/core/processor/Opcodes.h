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
    // False for call and rst
    bool inc_pc;
};

static const Opcode OPCODE_LOOKUP[256] = {
    {"NOP", 1, 4, 0, true},
    {"LD BC, " OP4, 3, 12, 0, true},
    {"LD (BC),A", 1, 8, 0, true},
    {"INC BC", 1, 8, 0, true},
    {"INC B", 1, 4, 0, true},
    {"DEC B", 1, 4, 0, true},
    {"LD B, " OP2, 2, 8, 0, true},
    {"RLCA", 1, 4, 0, true},
    {"LD (" OP4 "),SP", 3, 20, 0, true},
    {"ADD HL,BC", 1, 8, 0, true},
    {"LD A,(BC)", 1, 8, 0, true},
    {"DEC BC", 1, 8, 0, true},
    {"INC C", 1, 4, 0, true},
    {"DEC C", 1, 4, 0, true},
    {"LD C, " OP2, 2, 8, 0, true},
    {"RRCA", 1, 4, 0, true},

    {"STOP", 2, 4, 0, true},
    {"LD DE, " OP4, 3, 12, 0, true},
    {"LD (DE),A", 1, 8, 0, true},
    {"INC DE", 1, 8, 0, true},
    {"INC D", 1, 4, 0, true},
    {"DEC D", 1, 4, 0, true},
    {"LD D, " OP2, 2, 8, 0, true},
    {"RLA", 1, 4, 0, true},
    {"JR " OP2, 2, 12, 0, true},
    {"ADD HL,DE", 1, 8, 0, true},
    {"LD A,(DE)", 1, 8, 0, true},
    {"DEC DE", 1, 8, 0, true},
    {"INC E", 1, 4, 0, true},
    {"DEC E", 1, 4, 0, true},
    {"LD E, " OP2, 2, 8, 0, true},
    {"RRA", 1, 4, 0, true},

    {"JR NZ, " OP2, 2, 12, 0, true},
    {"LD HL, " OP4, 3, 12, 0, true},
    {"LD (HL+),A", 1, 8, 0, true},
    {"INC HL", 1, 8, 0, true},
    {"INC H", 1, 4, 0, true},
    {"DEC H", 1, 4, 0, true},
    {"LD H, " OP2, 2, 8, 0, true},
    {"DAA", 1, 4, 0, true},
    {"JR Z, " OP2, 2, 12, 0, true},
    {"ADD HL,HL", 1, 8, 0, true},
    {"LD A,(HL+)", 1, 8, 0, true},
    {"DEC HL", 1, 8, 0, true},
    {"INC L", 1, 4, 0, true},
    {"DEC L", 1, 4, 0, true},
    {"LD L, " OP2, 2, 8, 0, true},
    {"CPL", 1, 4, 0, true},

    {"JR NC, " OP2, 2, 12, 0, true},
    {"LD SP, " OP4, 3, 12, 0, true},
    {"LD (HL-),A", 1, 8, 0, true},
    {"INC SP", 1, 8, 0, true},
    {"INC (HL)", 1, 12, 0, true},
    {"DEC (HL)", 1, 12, 0, true},
    {"LD (HL), " OP2, 2, 12, 0, true},
    {"SCF", 1, 4, 0, true},
    {"JR C, " OP2, 2, 12, 0, true},
    {"ADD HL,SP", 1, 8, 0, true},
    {"LD A,(HL-)", 1, 8, 0, true},
    {"DEC SP", 1, 8, 0, true},
    {"INC A", 1, 4, 0, true},
    {"DEC A", 1, 4, 0, true},
    {"LD A, " OP2, 2, 8, 0, true},
    {"CCF", 1, 4, 0, true},

    {"LD B,B", 1, 4, 0, true},
    {"LD B,C", 1, 4, 0, true},
    {"LD B,D", 1, 4, 0, true},
    {"LD B,E", 1, 4, 0, true},
    {"LD B,H", 1, 4, 0, true},
    {"LD B,L", 1, 4, 0, true},
    {"LD B,(HL)", 1, 8, 0, true},
    {"LD B,A", 1, 4, 0, true},
    {"LD C,B", 1, 4, 0, true},
    {"LD C,C", 1, 4, 0, true},
    {"LD C,D", 1, 4, 0, true},
    {"LD C,E", 1, 4, 0, true},
    {"LD C,H", 1, 4, 0, true},
    {"LD C,L", 1, 4, 0, true},
    {"LD C,(HL)", 1, 8, 0, true},
    {"LD C,A", 1, 4, 0, true},

    {"LD D,B", 1, 4, 0, true},
    {"LD D,C", 1, 4, 0, true},
    {"LD D,D", 1, 4, 0, true},
    {"LD D,E", 1, 4, 0, true},
    {"LD D,H", 1, 4, 0, true},
    {"LD D,L", 1, 4, 0, true},
    {"LD D,(HL)", 1, 8, 0, true},
    {"LD D,A", 1, 4, 0, true},
    {"LD E,B", 1, 4, 0, true},
    {"LD E,C", 1, 4, 0, true},
    {"LD E,D", 1, 4, 0, true},
    {"LD E,E", 1, 4, 0, true},
    {"LD E,H", 1, 4, 0, true},
    {"LD E,L", 1, 4, 0, true},
    {"LD E,(HL)", 1, 8, 0, true},
    {"LD E,A", 1, 4, 0, true},

    {"LD H,B", 1, 4, 0, true},
    {"LD H,C", 1, 4, 0, true},
    {"LD H,D", 1, 4, 0, true},
    {"LD H,E", 1, 4, 0, true},
    {"LD H,H", 1, 4, 0, true},
    {"LD H,L", 1, 4, 0, true},
    {"LD H,(HL)", 1, 8, 0, true},
    {"LD H,A", 1, 4, 0, true},
    {"LD L,B", 1, 4, 0, true},
    {"LD L,C", 1, 4, 0, true},
    {"LD L,D", 1, 4, 0, true},
    {"LD L,E", 1, 4, 0, true},
    {"LD L,H", 1, 4, 0, true},
    {"LD L,L", 1, 4, 0, true},
    {"LD L,(HL)", 1, 8, 0, true},
    {"LD L,A", 1, 4, 0, true},

    {"LD (HL),B", 1, 8, 0, true},
    {"LD (HL),C", 1, 8, 0, true},
    {"LD (HL),D", 1, 8, 0, true},
    {"LD (HL),E", 1, 8, 0, true},
    {"LD (HL),H", 1, 8, 0, true},
    {"LD (HL),L", 1, 8, 0, true},
    {"HALT", 1, 4, 0, true},
    {"LD (HL),A", 1, 8, 0, true},
    {"LD A,B", 1, 4, 0, true},
    {"LD A,C", 1, 4, 0, true},
    {"LD A,D", 1, 4, 0, true},
    {"LD A,E", 1, 4, 0, true},
    {"LD A,H", 1, 4, 0, true},
    {"LD A,L", 1, 4, 0, true},
    {"LD A,(HL)", 1, 8, 0, true},
    {"LD A,A", 1, 4, 0, true},

    {"ADD A,B", 1, 4, 0, true},
    {"ADD A,C", 1, 4, 0, true},
    {"ADD A,D", 1, 4, 0, true},
    {"ADD A,E", 1, 4, 0, true},
    {"ADD A,H", 1, 4, 0, true},
    {"ADD A,L", 1, 4, 0, true},
    {"ADD A,(HL)", 1, 8, 0, true},
    {"ADD A,A", 1, 4, 0, true},
    {"ADC A,B", 1, 4, 0, true},
    {"ADC A,C", 1, 4, 0, true},
    {"ADC A,D", 1, 4, 0, true},
    {"ADC A,E", 1, 4, 0, true},
    {"ADC A,H", 1, 4, 0, true},
    {"ADC A,L", 1, 4, 0, true},
    {"ADC A,(HL)", 1, 8, 0, true},
    {"ADC A,A", 1, 4, 0, true},

    {"SUB B", 1, 4, 0, true},
    {"SUB C", 1, 4, 0, true},
    {"SUB D", 1, 4, 0, true},
    {"SUB E", 1, 4, 0, true},
    {"SUB H", 1, 4, 0, true},
    {"SUB L", 1, 4, 0, true},
    {"SUB (HL)", 1, 8, 0, true},
    {"SUB A", 1, 4, 0, true},
    {"SBC A,B", 1, 4, 0, true},
    {"SBC A,C", 1, 4, 0, true},
    {"SBC A,D", 1, 4, 0, true},
    {"SBC A,E", 1, 4, 0, true},
    {"SBC A,H", 1, 4, 0, true},
    {"SBC A,L", 1, 4, 0, true},
    {"SBC A,(HL)", 1, 8, 0, true},
    {"SBC A,A", 1, 4, 0, true},

    {"AND B", 1, 4, 0, true},
    {"AND C", 1, 4, 0, true},
    {"AND D", 1, 4, 0, true},
    {"AND E", 1, 4, 0, true},
    {"AND H", 1, 4, 0, true},
    {"AND L", 1, 4, 0, true},
    {"AND (HL)", 1, 8, 0, true},
    {"AND A", 1, 4, 0, true},
    {"XOR B", 1, 4, 0, true},
    {"XOR C", 1, 4, 0, true},
    {"XOR D", 1, 4, 0, true},
    {"XOR E", 1, 4, 0, true},
    {"XOR H", 1, 4, 0, true},
    {"XOR L", 1, 4, 0, true},
    {"XOR (HL)", 1, 8, 0, true},
    {"XOR A", 1, 4, 0, true},

    {"OR B", 1, 4, 0, true},
    {"OR C", 1, 4, 0, true},
    {"OR D", 1, 4, 0, true},
    {"OR E", 1, 4, 0, true},
    {"OR H", 1, 4, 0, true},
    {"OR L", 1, 4, 0, true},
    {"OR (HL)", 1, 8, 0, true},
    {"OR A", 1, 4, 0, true},
    {"CP B", 1, 4, 0, true},
    {"CP C", 1, 4, 0, true},
    {"CP D", 1, 4, 0, true},
    {"CP E", 1, 4, 0, true},
    {"CP H", 1, 4, 0, true},
    {"CP L", 1, 4, 0, true},
    {"CP (HL)", 1, 8, 0, true},
    {"CP A", 1, 4, 0, true},

    {"RET NZ", 1, 20, 0, true},
    {"POP BC", 1, 12, 0, true},
    {"JP NZ, " OP4, 3, 16, 0, true},
    {"JP " OP4, 3, 16, 0, true},
    {"CALL NZ, " OP4, 3, 24, 0, false},
    {"PUSH BC", 1, 16, 0, true},
    {"ADD A, " OP2, 2, 8, 0, true},
    {"RST 00H", 1, 16, 0, false},
    {"RET Z", 1, 20, 0, true},
    {"RET", 1, 16, 0, true},
    {"JP Z, " OP4, 3, 16, 0, true},
    {"CB EXT", 1, 4, 0, true},
    {"CALL Z, " OP4, 3, 24, 0, false},
    {"CALL " OP4, 3, 24, 0, false},
    {"ADC A, " OP2, 2, 8, 0, true},
    {"RST 08H", 1, 16, 0, false},

    {"RET NC", 1, 20, 0, true},
    {"POP DE", 1, 12, 0, true},
    {"JP NC, " OP4, 3, 16, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"CALL NC, " OP4, 3, 24, 0, false},
    {"PUSH DE", 1, 16, 0, true},
    {"SUB " OP2, 2, 8, 0, true},
    {"RST 10H", 1, 16, 0, false},
    {"RET C", 1, 20, 0, true},
    {"RETI", 1, 16, 0, true},
    {"JP C, " OP4, 3, 16, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"CALL C, " OP4, 3, 24, 0, false},
    {"UNDEFINED", 0, 0, 0, true},
    {"SBC A, " OP2, 2, 8, 0, true},
    {"RST 18H", 1, 16, 0, false},

    {"LD (FF+" OP2 "),A", 2, 12, 0, true},
    {"POP HL", 1, 12, 0, true},
    {"LD (FF00h+C),A", 1, 8, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"PUSH HL", 1, 16, 0, true},
    {"AND " OP2, 2, 8, 0, true},
    {"RST 20H", 1, 16, 0, false},
    {"ADD SP, " OP2, 2, 16, 0, true},
    {"JP (HL)", 1, 4, 0, true},
    {"LD (" OP4 "),A", 3, 16, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"XOR " OP2, 2, 8, 0, true},
    {"RST 28H", 1, 16, 0, false},

    {"LD A,(FF+" OP2 ")", 2, 12, 0, true},
    {"POP AF", 1, 12, 0, true},
    {"LD A,(C)", 2, 8, 0, true},
    {"DI", 1, 4, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"PUSH AF", 1, 16, 0, true},
    {"OR " OP2, 2, 8, 0, true},
    {"RST 30H", 1, 16, 0, false},
    {"LD HL,SP+" OP2, 2, 12, 0, true},
    {"LD SP,HL", 1, 8, 0, true},
    {"LD A,(" OP4 ")", 3, 16, 0, true},
    {"EI", 1, 4, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"CP " OP2, 2, 8, 0, true},
    {"RST 38H", 1, 16, 0, false}
};

static const Opcode CB_OPCODE_LOOKUP[256] = {
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"RL C", 2, 8, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"SWAP A", 2, 8, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"BIT 7,H", 2, 8, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"RES 0,A", 2, 8, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},

    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true},
    {"UNDEFINED", 0, 0, 0, true}
};