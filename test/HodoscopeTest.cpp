#include "Hodoscope.h"
int main(){

    Hodoscope h("TestHodoScope", 2 , 1);
    for(int i = 0 ; i < h.GetScintPlaneVector().size() ; i++){
    std::cout<<"---- " << h.GetScintPlaneVector()[i]->GetName() << " ----"<<std::endl;
    h.GetScintPlaneVector()[i]->PrintStrips();
    }
    //h.GetRpcVector()[0]->PrintStrips();

}