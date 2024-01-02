#pragma once
#include <Windows.h>

class Console
{
private:
	int width_var, height_var;
public:
	Console();
	int width() const;
	int height() const;
	void set_cursor(int x, int y) const;
	void clear();
};

