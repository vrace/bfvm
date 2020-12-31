#ifndef __BRAINFUCK_INSTRUCTIONS_H__
#define __BRAINFUCK_INSTRUCTIONS_H__

#include <vector>

enum class BrainfuckOpCode
{
	BF_NOP,
	BF_CELL_INC,		// >
	BF_CELL_DEC,		// <
	BF_VALUE_INC,		// +
	BF_VALUE_DEC,		// -
	BF_VALUE_OUTPUT,	// .
	BF_VALUE_READ,		// ,
	BF_JMP,				// [
	BF_JNZ,				// ]
};

struct BrainfuckInstruction
{
	BrainfuckOpCode op;
	std::vector<BrainfuckInstruction>::size_type label;
};

using BrainfuckCode = std::vector<BrainfuckInstruction>;

#endif
