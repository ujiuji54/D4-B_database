#pragma once

#include<iostream>
#include"database.hpp"
using namespace std;

class GUI {
	vector<vector<string>> table;
	vector<string> komoku_x;
	vector<string> komoku_y;
public:
	GUI(database input);
	void display();
};