#include<iostream>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

int main() {

	//�f�o�b�O�p�R�[�h
	database database;
	GUI GUI;
	
	//�f�[�^�x�[�X�J���p�f�o�b�O�R�[�h
	//GUI.update(database);
	//GUI.display();
	//cout << database.search_x("c") << endl; //�������f�o�b�O�������֐��ɕς���B

	GUI.GUI_main(database);
	/*  input output �̃e�X�g�悤
	database.file_output();
	database.file_input();
	*/
	return 0;

}
