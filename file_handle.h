#pragma once
#include <fstream>
#include "Map.h"
#include "MyString.h"

using namespace std;

Map read(const string file_path)
{
	ifstream file(file_path);

	if (not file.good())
	{
		cout << "Cant open file" << endl;
		exit(-1);
	}
	
	Map result;
	char line[1024];
	string str_line;
	List splitted_line;

	if (file.getline(line, 1024))
	{
		cout << "Setting columns" << endl;
		str_line = line;
		splitted_line = split(str_line);
		splitted_line.pop();
		splitted_line.lower_values();
		result.add_elements(splitted_line);
	}

	while (file.getline(line, 1024))
	{
		cout << "Setting rows" << endl;
		str_line = line;
		splitted_line = split(str_line);

		while (splitted_line.size() > result.size())
		{
			splitted_line.pop();
		}

		result.add_row(split(str_line));
	}
	cout << "File readed" << endl;
	return result;
}

