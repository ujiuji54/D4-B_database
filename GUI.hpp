#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

class GUI {
	vector<vector<string>> table;
	vector<string> komoku_x;
	vector<string> komoku_y;
public:
	void display();//���݂̃f�[�^�x�[�X�̏�Ԃ�\��
	void update(database input);//�f�[�^�x�[�X�̃f�[�^������Ă���
};
