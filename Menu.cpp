#include "Menu.h"
Menu::Menu()
{
	this->line = 0;
}

void Menu::center_text(const string text, const int all_height)
{
	int x, y;
	x = (console.width() - text.size()) / 2;
	y = ((console.height() - all_height) / 2) + this->line;

	this->console.set_cursor(x, y);

	cout << text;
	
	if (text[text.size() - 1] == '\n')
	{
		this->line++;
	}
}

void Menu::interface_handle()
{
	string interface_name = "menu";
	char choose;
	bool generate = true;
	Map data;
	int group_by = 1, height = console.height();

	while (true)
	{
		if (interface_name == "menu")
		{
			if (generate)
			{
				this->show(interface_name);
			}
			else
			{
				generate = true;
			}

			choose = _getch();

			switch (choose)
			{
			case 'g':
				interface_name = "default_open";
				break;
			case 'e':
				interface_name = "open";
				break;
			case 'q':
				interface_name = "exit";
				break;
			default:
				generate = false;
				break;
			}
		}
		else if (interface_name == "default_open")
		{
			this->show(interface_name);
			data = read("intc_us_d.csv");
			interface_name = "preview";
		}
		else if (interface_name == "open")
		{

		}
		else if (interface_name == "preview")
		{
			this->show(interface_name, data, this->console.width(), height, group_by);
			choose = _getch();
		}
		else if (interface_name == "exit")
		{
			exit(0);
		}
	}
}

void Menu::show(const string interface_name, const Map data, const int size_x, const int size_y, const int group_by)
{
	if (interface_name == "menu")
	{
		const int count_options = 3;
		this->line = 0;

		this->center_text("g -> Open file 'intc_us_data.csv'\n", count_options);
		this->center_text("e -> Open file\n", count_options);
		this->center_text("q -> Quit program\n", count_options);
	}
	else if (interface_name == "default_open")
	{
		console.clear();
		this->line = 0;
		this->center_text("Reading file...", 1);
	}
	else if (interface_name == "preview")
	{
		console.clear();

		this->line = 0;
		this->center_text("PREVIEW\n", console.height());
		this->center_text("+/- set hight of the chart | up/down set the range of a single chart bar\n", console.height());

		List* row = new List;
		double start, end, high, low;
		for (int i = 0; i < data.begin()->values()->size(); i += group_by)
		{
			row = data.get_row(i);
			start = atof(row->get(1).c_str());

			row = data.get_row(i + group_by);
			end = atof(row->get(4).c_str());

		}

	}
	else if (interface_name == "open")
	{
		cout << interface_name << endl;
	}
	
	
}


