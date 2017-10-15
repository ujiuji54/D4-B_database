#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

inline vector<vector<string>> database::return_table() { return table; }
inline vector<string> database::return_komoku_x() { return komoku_x; }
inline vector<string> database::return_komoku_y() { return komoku_y; }

inline void database::write(int x, int y, string input) {
	//指定した座標の要素を書き換える
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}


inline void database::add_komoku_x(string input) {
	//項目x追加(input:項目名)
}

inline void database::add_komoku_y(string input) {
	//項目y追加(input:項目名)
}

inline void database::file_output() {
	//ファイル出力
}

inline int database::search_x(string name) {
	//項目xから名前を検索(name:項目名)
}

inline int database::search_y(string name) {
	//項目yから名前を検索(name:項目名)
}

inline void database::sort(bool komoku, int n, bool order) {
	//項目xをソート(komoku:xかyか,n:vecter[n],order:昇順か降順か)
}