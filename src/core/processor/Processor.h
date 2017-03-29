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

#include <memory>


namespace Debugger {
    class Logger;
}; // namespace Debugger

namespace Core {

class GameBoy;
class MemoryMap;

class Processor
{
    friend class GameBoy;
    friend class Debugger::Logger;

    // 16-bit program counter and stack pointer
    Reg16 reg_PC;
    Reg16 reg_SP;
    // 8-bit register pairs are linked
    // together to make 16-bit registers
    Reg16 reg_AF;
    Reg16 reg_BC;
    Reg16 reg_DE;
    Reg16 reg_HL;
    // 8-bit registers point to halves of 16-bit pairs
    Reg8& reg_B = reg_BC.high;
    Reg8& reg_C = reg_BC.low;
    Reg8& reg_D = reg_DE.high;
    Reg8& reg_E = reg_DE.low;
    Reg8& reg_H = reg_HL.high;
    Reg8& reg_L = reg_HL.low;
    Reg8& reg_A = reg_AF.high;
    // flags
    bool F_Zero;
    bool F_Subtract;
    bool F_HalfCarry;
    bool F_Carry;

    // IME
    bool InterruptsEnabled = false;

    GameBoy* gameboy;
    std::shared_ptr<MemoryMap> memory_map;

    std::shared_ptr<Debugger::Logger> logger;

public:
    
    Processor(GameBoy* gameboy, std::shared_ptr<MemoryMap>& memory_map, std::shared_ptr<Debugger::Logger>& logger);

    int Tick();

    int ExecuteAt(u16 address);
    u8 ExecuteCBOpcode(u16 address);

    // instructions
    // load
    void ld_reg(Reg8& reg, u8 value);
    void ld_reg(Reg16& reg, u16 value);
    void ld_addr(u16 addr, u8 value);
    void ld_addr(u16 addr, u16 value);
    // inc/dec
    void inc(Reg8& reg);
    void inc(Reg16& reg16);
    void dec(Reg8& reg);
    void dec(Reg16& reg16);
    // add
    void add(Reg8& reg, u8 value);
    void add(Reg16& reg, u16 value);
    void add(Reg16& reg, s8 value);
    void adc(Reg8& reg, u8 value);
    // sub
    void sub(Reg8& reg, u8 value);
    void sbc(Reg8& reg, u8 value);
    // bitwise
    void and8(Reg8& reg, u8 value);
    void xor8(Reg8& reg, u8 value);
    void or8(Reg8& reg, u8 value);
    // compare
    void cp(u8 value);
    // jump
    void jr(s8 amt);
    void jp(u16 addr);
    void call(u16 addr);
    void ret();
    // stack
    void push(u16 value);
    void pop(Reg16& reg16);

    // CB opcodes
    // rotate
    void rl(Reg8& reg);
    // bit
    void bit(Reg8& reg, u8 bit);
};

}; // namespace Core