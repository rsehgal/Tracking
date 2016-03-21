#include "Tree.h"
#include <iostream>

int main(){

	Tree t;
	t.TreeW();
	t.TreeR();
	std::cout<<"---------------------------"<<std::endl;
	t.TreeR_V2("channel",45);
	return 0;
}