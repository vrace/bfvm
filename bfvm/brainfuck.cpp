#include <iostream>

#include "brainfuck_compiler.h"
#include "brainfuck_vm.h"

using std::string;

namespace
{
	const string SOURCE = "++++++++[>+>++>+++>++++>+++++>++++++>+++++++>++++++++>+++++++++>++++++++++>+++++++++++>++++++++++++>+++++++++++++>++++++++++++++>+++++++++++++++>++++++++++++++++<<<<<<<<<<<<<<<<-]>>>>>>>>>.<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<>>>>>>>>>>>>>>-.+<<<<<<<<<<<<<<>>>>.<<<<>>>>>>++.--<<<<<<>>>>>>.<<<<<<>>>>>>++.--<<<<<<>>>>>>+.-<<<<<<>>>>+.-<<<<.";
}

int main()
{
	string source = SOURCE;
	std::cout << "**** BRAINFUCK SOURCE CODE ****\n";
	std::cout << source << "\n";
	std::cout << "\n";

	std::cout << ">> COMPILING SOURCE CODE\n";
	BrainfuckCompiler compiler;
	auto code = compiler.compile(source);

	std::cout << ">> EXECUTING INSTRUCTIONS\n";
	BrainfuckVM vm(code);
	vm.execute();
	std::cout << "\n";

	return 0;
}
