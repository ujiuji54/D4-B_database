#pragma once

#include<iostream>
#include"database.hpp"
using namespace std;

class GUI {
	vector<vector<string>> table;
	vector<string> komoku_x;
	vector<string> komoku_y;
public:
	void display();//現在のデータベースの状態を表示
	void update(database input);//データベースのデータを取ってくる
	void GUI_main(database input);
};