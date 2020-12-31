#include "brainfuck_compiler.h"

using std::string;

BrainfuckCode BrainfuckCompiler::compile(const string &source)
{

	BrainfuckCode code;

	for (auto it = source.begin(); it != source.end(); ++it)
	{
		if (*it == '>')
		{
			code.push_back({ BrainfuckOpCode::BF_CELL_INC });
		}
		else if (*it == '<')
		{
			code.push_back({ BrainfuckOpCode::BF_CELL_DEC });
		}
		else if (*it == '+')
		{
			code.push_back({ BrainfuckOpCode::BF_VALUE_INC });
		}
		else if (*it == '-')
		{
			code.push_back({ BrainfuckOpCode::BF_VALUE_DEC });
		}
		else if (*it == '.')
		{
			code.push_back({ BrainfuckOpCode::BF_VALUE_OUTPUT });
		}
		else if (*it == ',')
		{
			code.push_back({ BrainfuckOpCode::BF_VALUE_READ });
		}
		else if (*it == '[')
		{
			auto label = search_label(it, source.end());
			auto restore = (it - source.begin()) + 1;
			auto dest = label - source.begin();
			_labels.push_back(restore);
			code.push_back({ BrainfuckOpCode::BF_JMP, static_cast<BrainfuckCode::size_type>(dest) });
		}
		else if (*it == ']')
		{
			auto label = source.length();
			if (!_labels.empty())
			{
				label = _labels.back();
				_labels.pop_back();
			}
			code.push_back({ BrainfuckOpCode::BF_JNZ, label });
		}
	}

	return code;
}

std::string::const_iterator BrainfuckCompiler::search_label(std::string::const_iterator it, std::string::const_iterator end)
{
	auto counter = 1;

	for (++it; it != end; ++it)
	{
		switch (*it)
		{
		case '[':
			++counter;
			break;

		case ']':
			--counter;
			break;

		default:
			break;
		}

		if (!counter)
			return it;
	}

	return end;
}
