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
	vector<string> komoku_y = { "d","e","æåžãŽå" };
	//fobOpf[^đi[
	vector<vector<string> > return_table();
	vector<string> return_komoku_x();
	vector<string> return_komoku_y();
	void write(string x_name, string y_name, string input);//wčĩŊĀWĖvfđĢˇĻé
	void add_komoku_x(string input);//ÚxĮÁ(input:Úŧ)
	void add_komoku_y(string input);//ÚyĮÁ(input:Úŧ)
	void remove_komoku_x(string input);
	void remove_komoku_y(string input);
	int strlen_conversion(string str);
	void file_output(string name);//t@CoÍ
	void file_output2(string name);
	void file_input(string name);//t@CŠįf[^Ėæž
	int search_x(string name); //ÚxŠįŧOđõ(name:Úŧ)
	int search_y(string name); //ÚyŠįŧOđõ(name:Úŧ)
	void sort(bool komoku,string name,bool order); //Úxđ\[g(komoku:xŠyŠ,name:Úŧ,order:¸Š~Š)
};
