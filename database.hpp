#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class database{
private:
	vector<vector<string> > table = {
		{"9","2","3000000"},
		{"4","5","60000"},
		{"7","8","9000000"},
	};
	vector<string> komoku_x = {"a","b","c"};
	vector<string> komoku_y = { "d","e","f" };
	//�f�o�b�O�p�f�[�^���i�[

public:
	vector<vector<string> > return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(string x_name, string y_name, string input);//�w�肵�����W�̗v�f������������
	void add_komoku_x(string input);//����x�ǉ�(input:���ږ�)
	void add_komoku_y(string input);//����y�ǉ�(input:���ږ�)
	void file_output();//�t�@�C���o��
	void file_input();//�t�@�C������f�[�^�̎擾
	int search_x(string name); //����x���疼�O������(name:���ږ�)
	int search_y(string name); //����y���疼�O������(name:���ږ�)
	void sort(bool komoku,string name,bool order); //����x���\�[�g(komoku:x��y��,name:���ږ�,order:�������~����)
};
