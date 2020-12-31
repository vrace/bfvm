#include <iostream>
#include "brainfuck_vm.h"

BrainfuckVM::BrainfuckVM(const BrainfuckCode& code, BrainfuckCellBlock::size_type cellSize)
	: _ip(0)
	, _cp(0)
	, _code(code)
	, _cells(cellSize)
{

}

void BrainfuckVM::execute()
{
	while (!is_code_finished())
	{
		auto& instruction = current_instruction();
		
		switch (instruction.op)
		{
		case BrainfuckOpCode::BF_CELL_INC:
			++_cp;
			++_ip;
			break;

		case BrainfuckOpCode::BF_CELL_DEC:
			--_cp;
			++_ip;
			break;

		case BrainfuckOpCode::BF_VALUE_INC:
			if (is_cell_valid())
			{
				++_cells[_cp];
			}
			++_ip;
			break;

		case BrainfuckOpCode::BF_VALUE_DEC:
			if (is_cell_valid())
			{
				--_cells[_cp];
			}
			++_ip;
			break;

		case BrainfuckOpCode::BF_VALUE_OUTPUT:
			if (is_cell_valid())
			{
				std::cout << static_cast<char>(_cells[_cp]);
			}
			++_ip;
			break;

		case BrainfuckOpCode::BF_VALUE_READ:
			if (is_cell_valid())
			{
				char ch;
				std::cin >> ch;
				_cells[_cp] = static_cast<BrainfuckCell>(ch);
			}
			++_ip;
			break;

		case BrainfuckOpCode::BF_JMP:
			_ip = static_cast<BrainfuckCode::size_type>(instruction.label);
			break;

		case BrainfuckOpCode::BF_JNZ:
			if (is_cell_valid())
			{
				if (_cells[_cp])
				{
					_ip = static_cast<BrainfuckCode::size_type>(instruction.label);
				}
				else
				{
					++_ip;
				}
			}
			break;

		default:
			break;
		}
	}
}

bool BrainfuckVM::is_code_finished() const
{
	return _ip < 0 || _ip >= _code.size();
}

bool BrainfuckVM::is_cell_valid() const
{
	return _cp >= 0 && _cp < _cells.size();
}

const BrainfuckInstruction& BrainfuckVM::current_instruction() const
{
	return _code[_ip];
}
