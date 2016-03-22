#include "Tree.h"
#include <TH1F.h>
#include <TApplication.h>

using namespace Tracking;

void Tree::CreateHistogram(std::string bName){

  TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  TH1F *h = new TH1F("h",bName.c_str(),100,20000,21000);
  Channel *ch = 0;
  TBranch *b = 0;
  t->SetBranchAddress(bName.c_str(),&ch,&b);
  for(int evNo = 0 ; evNo < numOfEvents ; evNo++){
    Long64_t tentry = t->LoadTree(evNo);
    b->GetEntry(tentry);
    for(int i = 0 ; i< ch->size() ; i++){
      h->Fill(ch->at(i));
    }
  }

  t->ResetBranchAddresses();
  h->Draw();
  fApp->Run();
  //h->Show();
}
