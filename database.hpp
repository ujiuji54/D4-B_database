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
	//�f�o�b�O�p�f�[�^���i�[

public:
	vector<vector<string>> return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(int x, int y, string input);//�w�肵�����W�̗v�f������������
	void add_komoku_x(string input);//����x�ǉ�
	void add_komoku_y(string input);//����y�ǉ�
	void file_output();//�t�@�C���o��
};