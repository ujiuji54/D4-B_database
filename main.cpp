#include<iostream>
#include<vector>
#include"database.cpp"
#include"GUI.cpp"
using namespace std;

int main() {

	//�f�o�b�O�p�R�[�h
	database database;
	GUI GUI(database);
	
	GUI.display();

	return 0;

}