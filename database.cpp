#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

vector<vector<string> > database::return_table() { return table; }
vector<string> database::return_komoku_x() { return komoku_x; }
vector<string> database::return_komoku_y() { return komoku_y; }

void database::write(string x_name, string y_name, string input) {
	//指定した座標の要素を書き換える
	int x, y;
	x = search_x(x_name);
	y = search_y(y_name);
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}


void database::add_komoku_x(string input) {
	cout << "minami test" << endl; 
	//項目x追加(input:項目名)
}

void database::add_komoku_y(string input) {
	//項目y追加(input:項目名)
}

void database::file_output() {
	//ファイル出力
}

int database::search_x(string name) {
	//項目xから名前を検索(name:項目名)
	return 0;
}

int database::search_y(string name) {
	//項目yから名前を検索(name:項目名)
	return 0;
}

void database::sort(bool komoku, string name, bool order) {
	//項目xをソート(komoku:xかyか,n:vecter[n],order:昇順か降順か)
}
