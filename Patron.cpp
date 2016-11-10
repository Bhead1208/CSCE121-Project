// Taks
// fedility investments
// moleks
#include "Patron.h"
Patron::Patron(){
	patronName = "Jhon"+"-"+"Doe";
	money = 0;
	idNum = 000000000;
}
Patron::Patron(string first, string second){
	patronName = first +"-"+ second;
	money = 0;
	idNum = 000000000;
}
void Patron::get_Name(){
	return PatronName;
}
void Patron::set_Name(string str){
	patronName = str;
}
double Patron::get_Money(){
	return money;
}
void Patron::set_Money(double mon){
	money = mon;
}
int Patron::get_idNum(){
	return id; 
}
int Patron::set_idNum(num){
	idNum = num;
}