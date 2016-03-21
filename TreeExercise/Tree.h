
#include <TTree.h>
#include <vector>
#include <algorithm>
#include "base/Global.h"
#include <string>
#include <TTree.h>

using namespace Tracking;

class Tree{
	
	private:
		int numOfEvents;
		//Channel ch;
		Channel ch;
		std::string rootFile;
		TTree *t;
		TFile *f;

	public:
		Tree();
		~Tree();
		void TreeW();
		void TreeR();
		void TreeR_V2(std::string bName, int entry);
		

};
