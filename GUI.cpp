#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

void GUI::display() {
	cout << "-----------------------" << endl;
	string str;
	int box=0;
	for (int i = 0; i < komoku_y.size(); i++){
		if(komoku_y[i].size() > box) box = komoku_y[i].size(); 
	}
	
	/*string boxx;
	for (int i = 0; i < table.size(); i++){
		for (int j = 0; j < table[i].size(); j++){
			if(boxx[j] << table[i][j].size()) boxx[j] = table[i][j].size();
			cout << table[i][j].size() << endl;
		}
	}*/
	
	for(int j = 0; j <= box; j++) cout << " ";
	
	for (int i = 0; i < komoku_x.size(); i++){
		cout << komoku_x[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << komoku_y[i] << " ";
		for(int j = 0; j < box - komoku_y[i].size();j++) cout << " ";
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
			//for(int a = 0; a < boxx[j] - table[i][j].size();a++) cout << " ";
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

void GUI::write(database input) {
	string x;
	string y;
	string inf;
	cout << "�f�[�^����͂��郂�[�h�ł��B���W�w���A�f�[�^����͂��܂��B" << endl;
	cout << "���̍��ږ�����͂��Ă�������" << endl;
	cin >> x;
	cout << "�c�̍��ږ�����͂��Ă�������" << endl;
	cin >> y;
	cout << "������͂��Ă�������" << endl;
	cin >> inf;
	input.write(x,y,inf);
}

void GUI::add_komoku(database input) {
	int xory;
	string name;
	cout<<"���̍��ڂ�ǉ�����Ȃ�0,�c�̍��ڂ�ǉ�����Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"�ǉ����鍀�ږ�����͂��Ă�������"<<endl;
	cin>>name;
	if(xory==0){
		input.add_komoku_x(name);
	}
	if(xory==1){
		input.add_komoku_y(name);
	}
}

void GUI::sort(database input) {
	bool xory;
	string name;
	bool order;
	cout<<"���̍��ڂ���ёւ���Ȃ�0,�c�̍��ڂ���ёւ���Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"���ёւ��鍀�ڂ̖��O����͂��Ă�������"<<endl;
	cin>>name;
	cout<<"�����ɂ������Ȃ�0,�~���ɂ������Ȃ�1����͂��Ă�������"<<endl;
	cin>>order;
		//database.sort(xory,name,order);
}

void GUI::search(database input) {
	int xory;
	string name;
	cout<<"���̍��ڂ��猟������Ȃ�0,�c�̍��ڂ��猟������Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"�������鍀�ږ�����͂��Ă�������"<<endl;
	if(xory==0){
		input.search_x(name);
	}
	if(xory==1){
		input.search_y(name);
	}
}

void GUI::file_output(database input) {
	input.file_output();
	cout<<"test.txt�ɏo�͂��������܂���"<<endl;
}

void GUI::GUI_main(database input) {
	int mode=0;
	while (mode!=6) {
		update(input);
		display();
		//cout << "���p�������@�\��I�����Ă�������" << endl;
		cout << "1  : ���̏�������" << endl;
		cout << "2  : �f�[�^�x�[�X���ڂ̒ǉ�" << endl;
		cout << "3  : ���ڂ̕��ёւ�" << endl;
		cout << "4  : ���ڂ̌���" << endl;
		cout << "5  : �f�[�^�x�[�X�����t�@�C���o��" << endl;
		cout << "6  : �I��" << endl;
		cin >> mode; //mode�I��
		switch (mode){
		case 1:
			write(input);
			break;
		case 2:
			add_komoku(input);
			break;
		case 3:
			sort(input);
			break;
		case 4:
			search(input);
			break;
		case 5:
			file_output(input);
			break;
		case 6:
			cout << "�I�����܂��D" << endl;
			break;
		default:
			cout << "�����Ȑ����ł��D���͂������Ă�������" << endl;
			break;
		}
	}
}
