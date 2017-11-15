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
	vector<string> komoku_y = { "d","e","最後の列" };
	//�f�o�b�O�p�f�[�^���i�[
	vector<vector<string> > return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(string x_name, string y_name, string input);//�w�肵�����W�̗v�f������������
	void add_komoku_x(string input);//����x�ǉ�(input:���ږ�)
	void add_komoku_y(string input);//����y�ǉ�(input:���ږ�)
	void remove_komoku_x(string input);
	void remove_komoku_y(string input);
	int strlen_conversion(string str);
	void file_output(string name);//�t�@�C���o��
	void file_output2(string name);
	void file_input(string name);//�t�@�C������f�[�^�̎擾
	int search_x(string name); //����x���疼�O������(name:���ږ�)
	int search_y(string name); //����y���疼�O������(name:���ږ�)
	void sort(bool komoku,string name,bool order); //����x���\�[�g(komoku:x��y��,name:���ږ�,order:�������~����)
};
