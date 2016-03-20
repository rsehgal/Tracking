
#include <TTree.h>
#include <vector>
#include <algorithm>
#include "base/Global.h"
#include <string>

using namespace Tracking;

class Tree{
	
	private:
		int numOfEvents;
		//Channel ch;
		Channel ch;
		std::string rootFile;

	public:
		Tree();
		~Tree();
		void TreeW();
		void TreeR();


};
