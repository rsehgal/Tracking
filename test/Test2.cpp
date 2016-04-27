#include "Tree.h"
#include <iostream>

int main(){

//	Tree t;
//	t.TreeW();
//	t.TreeR();
//	std::cout<<"---------------------------"<<std::endl;
//	t.TreeR_V2("channel",45);


#define REAL_FILE
#ifdef REAL_FILE
  Tree t("6147.root","BSC_DATA_TREE");
for(int j = 0 ; j < 1000 ; j++){
  Channel *ch = t.GetEntry("Module3_LE_CH32",j);
  for(int i = 0 ; i  < ch->size() ; i++){
  std::cout<<"value : "<<ch->at(i) <<" , ";
  }

  std::cout<<std::endl;
}

	return 0;
#endif
}
