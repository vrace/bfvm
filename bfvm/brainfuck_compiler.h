#ifndef __BRAINFUCK_COMPILER_H__
#define __BRAINFUCK_COMPILER_H__

#include <string>
#include <vector>

#include "brainfuck_vm.h"

class BrainfuckCompiler
{
public:
	BrainfuckCode compile(const std::string& source);

private:
	std::string::const_iterator search_label(std::string::const_iterator it, std::string::const_iterator end);
	

private:
	std::vector<std::string::size_type> _labels;
};

#endif
