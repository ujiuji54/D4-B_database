#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

vector<vector<string> > database::return_table() { return table; }
vector<string> database::return_komoku_x() { return komoku_x; }
vector<string> database::return_komoku_y() { return komoku_y; }

void database::write(string x_name, string y_name, string input) {
	//�w�肵�����W�̗v�f������������
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
	//����x�ǉ�(input:���ږ�)
}

void database::add_komoku_y(string input) {
	//����y�ǉ�(input:���ږ�)
}

void database::file_output() {
	//�t�@�C���o��
}

int database::search_x(string name) {
	//����x���疼�O������(name:���ږ�)
	return 0;
}

int database::search_y(string name) {
	//����y���疼�O������(name:���ږ�)
	return 0;
}

void database::sort(bool komoku, string name, bool order) {
	//����x���\�[�g(komoku:x��y��,n:vecter[n],order:�������~����)
}
