#include<iostream>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

int main() {

	//�f�o�b�O�p�R�[�h
	database database;
	GUI GUI;
	
	GUI.update(database);
	GUI.display();

	return 0;

}
