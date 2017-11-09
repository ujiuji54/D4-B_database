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
	cout<<"���̍��ڂ�ǉ�����Ȃ�1,�c�̍��ڂ�ǉ�����Ȃ�2����͂��Ă�������"<<endl;
	cin>>xory;
	cout<<"���ږ�����͂��Ă�������"<<endl;
	cin>>input;
	if(xory==1){
		//database.add_komoku_x(input);
	}
	if(xory==2){
		//database.add_komoku_y(input);
	}
}

void GUI::sort() {
	
	//database.sort()

}

void GUI::search() {
	string input;
	cout<<"���̍��ڂ��猟������Ȃ�1,�c�̍��ڂ��猟������Ȃ�2����͂��Ă�������"<<endl;
	database.search()

}

void GUI::file_output() {
	database.file_out()

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
