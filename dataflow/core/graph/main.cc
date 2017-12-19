/*
 * main.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include "core/ops/operator.h"
#include "core/ops/conv.h"

int main() {
  dataflow::Conv* conv;
  conv = dynamic_cast<dataflow::Conv*>(dataflow::CREATE_OP("conv"));
  std::cout << conv->get_op_name() << std::endl;
  return 0;
}


