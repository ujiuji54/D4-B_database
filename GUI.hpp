#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

class GUI {
	vector<vector<string> > table;
	vector<string> komoku_x;
	vector<string> komoku_y;
public:
	void GUI_main(database& input);
	void display(database& input);//���݂̃f�[�^�x�[�X�̏�Ԃ�\��
	void update(database& input);//�f�[�^�x�[�X�̃f�[�^������Ă���

	void write(database& input);//�f�[�^�x�[�X�̃f�[�^������������(database::write()���g��)
	void add_komoku(database& input);//�f�[�^�x�[�X�̍��ڂ�ǉ�����(database::add_komoku_x()��database::add_komoku_y()���g��)
	void remove_komoku(database& input);
	void sort(database& input);//�f�[�^�x�[�X�̍��ڂ���ёւ���(databasse::sort()���g��)
	void search(database& input);//�f�[�^�x�[�X���獀�ڂ�T��(database::search_x()��database::search_y()���g��)
	void file_output(database& input);//�f�[�^�x�[�X�̃f�[�^���t�@�C���ɏo�͂���(database::file_out()���g��)
	void file_input(database& input);
	void file_copy();
};
