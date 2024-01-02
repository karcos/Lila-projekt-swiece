#pragma once
#include <iostream>
#include <conio.h>
#include "Console.h"
#include "FileHandle.h"

using namespace std;

class Menu
{
private:
	Console console;
	int line;

	void center_text(const string text, const int all_height);
	void show(const string interface_name, const Map data = Map(), const int size_x = 0, const int size_y = 0, const int group_by = 0);
public:
	Menu();
	void interface_handle();
	
};

