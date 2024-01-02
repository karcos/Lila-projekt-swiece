#include "Console.h"

Console::Console()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    this->width_var = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    this->height_var = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int Console::width() const
{
    return this->width_var;
}

int Console::height() const
{
    return this->height_var;
}

void Console::set_cursor(int x, int y) const
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}

void Console::clear()
{
    system("cls");
}
