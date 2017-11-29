#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class database{
private:
public:
	vector<vector<string> > table = {
		{"9","vector","3000000"},
		{"4","iostream","60000"},
		{"7","string","9000000"},
	};
	vector<string> komoku_x = {"a","b","c"};
	vector<string> komoku_y = { "d","e","f" };
	//デバッグ用データを格納
	vector<vector<string> > return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(string x_name, string y_name, string input);//指定した座標の要素を書き換える
	void add_komoku_x(string input);//項目x追加(input:項目名)
	void add_komoku_y(string input);//項目y追加(input:項目名)
	void remove_komoku_x(string input);
	void remove_komoku_y(string input);
	int strlen_conversion(string str);
	void file_output(string name);//ファイル出力
	void file_output2(string name);
	bool file_input(string name);//ファイルからデータの取得
	int search_x(string name); //項目xから名前を検索(name:項目名)
	int search_y(string name); //項目yから名前を検索(name:項目名)
	void sort(bool komoku,string name,bool order); //項目xをソート(komoku:xかyか,name:項目名,order:昇順か降順か)
};
