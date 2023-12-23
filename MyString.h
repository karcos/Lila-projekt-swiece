#pragma once

List split(const string& text, const char delimiter = ',')
{
	string word = "";
	List result;

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] != delimiter)
		{
			word += text[i];
		}
		if(text[i] == delimiter or i + 1 == text.size())
		{
			result.add(word);
			word = "";
		}
	}

	return result;

}
