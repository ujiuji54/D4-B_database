#include<iostream>
#include<vector>
#include"database.cpp"
#include"GUI.cpp"
using namespace std;

int main() {

	//デバッグ用コード
	database database;
	GUI GUI;
	
	GUI.GUI_main(database);

	return 0;

}