#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

class GUI {
	vector<vector<string> > table;
	vector<string> komoku_x;
	vector<string> komoku_y;
public:
	void GUI_main(database& input);
	void display(database& input);//現在のデータベースの状態を表示
	void update(database& input);//データベースのデータを取ってくる

	void write(database& input);//データベースのデータを書き換える(database::write()を使う)
	void add_komoku(database& input);//データベースの項目を追加する(database::add_komoku_x()かdatabase::add_komoku_y()を使う)
	void remove_komoku(database& input);
	void sort(database& input);//データベースの項目を並び替える(databasse::sort()を使う)
	void search(database& input);//データベースから項目を探す(database::search_x()かdatabase::search_y()を使う)
	void file_output(database& input);//データベースのデータをファイルに出力する(database::file_out()を使う)
	void file_input(database& input);
	void file_copy();
};
