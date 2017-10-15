#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

inline vector<vector<string>> database::return_table() { return table; }
inline vector<string> database::return_komoku_x() { return komoku_x; }
inline vector<string> database::return_komoku_y() { return komoku_y; }

inline void database::write(int x, int y, string input) {
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}


inline void database::add_komoku_x(string input) {

}

inline void database::add_komoku_y(string input) {

}

inline void database::file_output() {

}