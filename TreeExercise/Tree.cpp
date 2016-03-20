#include "Tree.h"
#include <TFile.h>
#include <TBranch.h>
#include <iostream>

Tree::Tree(){
	numOfEvents = 100;
	rootFile = "test.root";
}

Tree::~Tree(){}

void Tree::TreeW(){

	TFile f(rootFile.c_str(),"RECREATE");
	TTree t("testTree","A Tree with STL vectors");
    //t.Branch("channel",ch, "ch[3]/I");
    t.Branch("channel",&ch);

    for(int i= 0 ; i < numOfEvents ; i++){

    	ch.clear(); // clearing the vector
    	ch.push_back(1);
    	ch.push_back(8);
   		ch.push_back(3);

    	t.Fill();
    }

    f.Write();
 
}

void Tree::TreeR(){

	Channel *ch;
	TFile *f = new TFile(rootFile.c_str());
	TTree *t = (TTree*)f->Get("testTree");
	TBranch *b = t->GetBranch("channel");
	t->SetBranchAddress("channel",&ch,&b);
	Int_t nentries = t->GetEntries();
	for(Int_t i = 0 ; i < nentries ; i++){
		b->GetEntry(i);
		std::cout<<"val : "<<ch->at(1)<<std::endl;
	}


}
