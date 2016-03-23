#include "RPC.h"
#include <iostream>
using namespace Tracking;

int main(){

  RPC rpc(2,96,"FirstRpc");
  rpc.PrintStripNames();
  RPC rpc2(3,64,"FirstRpc");
    rpc2.PrintStripNames();

}
