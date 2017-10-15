#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class database{
private:
	vector<vector<string>> table = {
		{"1","2","3"},
		{"4","5","6"},
		{"7","8","9"},
	};
	vector<string> komoku_x = {"a","b","c"};
	vector<string> komoku_y = { "d","e","f" };
	//デバッグ用データを格納

public:
	vector<vector<string>> return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(int x, int y, string input);//指定した座標の要素を書き換える
	void add_komoku_x(string input);//項目x追加
	void add_komoku_y(string input);//項目y追加
	void file_output();//ファイル出力
};