#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class database{
private:
public:
	vector<vector<string> > table = {
		{"9","vector","3000000"},
		{"4","iostream","60000"},
		{"7","string","9000000"},
	};
	vector<string> komoku_x = {"a","b","c"};
	vector<string> komoku_y = { "d","e","æœ€å¾Œã®åˆ—" };
	//ƒfƒoƒbƒO—pƒf[ƒ^‚ğŠi”[
	vector<vector<string> > return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(string x_name, string y_name, string input);//w’è‚µ‚½À•W‚Ì—v‘f‚ğ‘‚«Š·‚¦‚é
	void add_komoku_x(string input);//€–Úx’Ç‰Á(input:€–Ú–¼)
	void add_komoku_y(string input);//€–Úy’Ç‰Á(input:€–Ú–¼)
	void remove_komoku_x(string input);
	void remove_komoku_y(string input);
	int strlen_conversion(string str);
	void file_output(string name);//ƒtƒ@ƒCƒ‹o—Í
	void file_output2(string name);
	void file_input(string name);//ƒtƒ@ƒCƒ‹‚©‚çƒf[ƒ^‚Ìæ“¾
	int search_x(string name); //€–Úx‚©‚ç–¼‘O‚ğŒŸõ(name:€–Ú–¼)
	int search_y(string name); //€–Úy‚©‚ç–¼‘O‚ğŒŸõ(name:€–Ú–¼)
	void sort(bool komoku,string name,bool order); //€–Úx‚ğƒ\[ƒg(komoku:x‚©y‚©,name:€–Ú–¼,order:¸‡‚©~‡‚©)
};
