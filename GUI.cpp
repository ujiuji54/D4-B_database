#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

void GUI::display() {
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

void GUI::update(database input) {
	table = input.return_table();
	komoku_x = input.return_komoku_x();
	komoku_y = input.return_komoku_y();
}

void GUI::write() {}

void GUI::add_komoku() {}

void GUI::sort() {}

void GUI::search() {}

void GUI::file_output() {}

void GUI::GUI_main(database input) {
	int mode;
	while (mode!=-1) {
		update(input);
		display();
		cin >> mode; //mode‘I‘ð
		switch (mode){
		case 1:

		case 2:

		default:
			break;
		}
	}
}