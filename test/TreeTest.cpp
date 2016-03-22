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
  Tree t("6133.root","BSC_DATA_TREE");
  Channel *ch = t.GetEntry("Module2_LE_CH31",45);
  for(int i = 0 ; i  < ch->size() ; i++){
  std::cout<<"value : "<<ch->at(i) <<" , ";
  }
  std::cout<<std::endl;

  //Creating histogram;
  t.CreateHistogram("Module2_LE_CH31");

#else
  Tree t("test.root","testTree");
  t.TreeR_V2("channel",45);
#endif
    std::cout<<"Num Of Events : "<< t.GetNumOfEvents() <<std::endl;

    //Channel *ch = t.GetEntry("Module2_LE_CH31",45);

	return 0;



}
