#ifndef __BRAINFUCK_VM_H__
#define __BRAINFUCK_VM_H__

#include "brainfuck_instructions.h"

class BrainfuckVM
{
public:
	using BrainfuckCell = unsigned char;
	using BrainfuckCellBlock = std::vector<BrainfuckCell>;

	BrainfuckVM(const BrainfuckCode &code, BrainfuckCellBlock::size_type cellSize = 30000);
	void execute();

private:
	bool is_code_finished() const;
	bool is_cell_valid() const;
	const BrainfuckInstruction& current_instruction() const;

private:
	BrainfuckCode _code;
	BrainfuckCode::size_type _ip;
	BrainfuckCellBlock _cells;
	BrainfuckCellBlock::size_type _cp;
};

#endif
