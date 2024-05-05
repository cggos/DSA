// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "tree/binary_tree_01.h"

int main(int argc, char *argv[]) {
  BinTree BT;
  BT = CreateBinTree();
  LevelOrderTraversal(BT);
  return 0;
}