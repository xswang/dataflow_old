/*
 * main.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <fstream>
#include "core/ops/operator.h"
#include "core/ops/conv.h"
#include "core/proto/dataflow.pb.h"
#include "core/graph/proto_parse.h"

int main() {
  dataflow::Conv* conv;
  conv = dynamic_cast<dataflow::Conv*>(dataflow::CREATE_OP("conv"));
  std::cout << conv->get_op_name() << std::endl;
  //std::ifstream in("models/googlenet_model_complete.txt", std::ios::in);
  dataflow::GraphDef graph_def;
  //dataflow::NodeDef node_def;
  const char* model = "/root/xiaoshu/dataflow/dataflow/models/googlenet_model_complete.txt";
  dataflow::PbParse* pb;
  bool res = pb->ReadProtoFromTextFile(model, &graph_def);
  std::cout << graph_def.node_def_size() << std::endl;
  return 0;
}


