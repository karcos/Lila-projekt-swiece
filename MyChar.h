#pragma once
#include <iostream>
using namespace std;

string lower(string text)
{
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] >= 65 and text[i] <= 90)
		{
			text[i] += 32;
		}
	}

	return text;
}
