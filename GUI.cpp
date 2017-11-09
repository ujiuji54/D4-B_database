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

void GUI::write() {
}

void GUI::add_komoku() {
	int xory;
	string input;
	cout<<"���̍��ڂ�ǉ�����Ȃ�0,�c�̍��ڂ�ǉ�����Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"�ǉ����鍀�ږ�����͂��Ă�������"<<endl;
	cin>>input;
	if(xory==0){
		//database.add_komoku_x(input);
	}
	if(xory==1){
		//database.add_komoku_y(input);
	}
}

void GUI::sort() {
	bool xory;
	string input;
	bool order;
	cout<<"���̍��ڂ���ёւ���Ȃ�0,�c�̍��ڂ���ёւ���Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"���ёւ��鍀�ڂ̖��O����͂��Ă�������"<<endl;
	cin>>input;
	cout<<"�����ɂ������Ȃ�0,�~���ɂ������Ȃ�1����͂��Ă�������"<<endl;
	cin>>order;
		//database.sort(xory,input,order);
}

void GUI::search() {
	int xory
	string input;
	cout<<"���̍��ڂ��猟������Ȃ�0,�c�̍��ڂ��猟������Ȃ�1����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"�������鍀�ږ�����͂��Ă�������"<<endl;
	if(xory==0){
		//database.search_x(input);
	}
	if(xory==1){
		//database.search_y(input);
	}
}

void GUI::file_output() {
	//database.file_out();
	cout<<"test.txt�ɏo�͂��������܂���"<<endl;
}

void GUI::GUI_main(database input) {
	int mode=0;
	while (mode!=-1) {
		update(input);
		display();
		cin >> mode; //mode�I��
		switch (mode){
		case 1:
			write();
		case 2:
			add_komoku();
		case 3:
			sort();
		case 4:
			search();
		case 5:
			file_output();
		default:
			break;
		}
	}
}
