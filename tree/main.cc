#include "tree/binary_tree_01.h"

int main(int argc, char *argv[]) {
  BinTree BT;
  BT = CreateBinTree();
  LevelOrderTraversal(BT);
  return 0;
}