#include<iostream>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

inline void GUI::display() {
	cout << "-----------------------" << endl;
	for (int i = 0; i < komoku_x.size(); i++)cout << komoku_x[i] << " ";
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << komoku_y[i] << " ";
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

inline void GUI::update(database input) {
	table = input.return_table();
	komoku_x = input.return_komoku_x();
	komoku_y = input.return_komoku_y();
}
