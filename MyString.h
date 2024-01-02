#pragma once
#include <iostream>
#include <cstdlib>
#include "List.h"

using namespace std;

extern List split(const string& text, const char delimiter = ',');
