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
#include "core/graph/graph_viz.h"
#include "core/graph/udf_graph.h"

#include "gflags/include/gflags/gflags.h"
#include "glog/include/glog/logging.h"

DEFINE_string(model_file, "/root/xiaoshu/dataflow/dataflow/models/googlenet_model_complete.txt", "");

int main() {
  dataflow::Conv* conv;
  conv = dynamic_cast<dataflow::Conv*>(dataflow::CREATE_OP("conv"));
  std::cout << conv->get_op_name() << std::endl;
  LOG(INFO) << conv->get_op_name();
  //std::ifstream in("models/googlenet_model_complete.txt", std::ios::in);
  dataflow::GraphDef graph_def;
  //dataflow::NodeDef node_def;
  // const char* model = "/root/xiaoshu/dataflow/dataflow/models/googlenet_model_complete.txt";
  dataflow::PbParse* pb;
  bool res = pb->ReadProtoFromTextFile(FLAGS_model_file.c_str(), &graph_def);
  dataflow::UdfGraph udf_graph(graph_def);
  std::cout<<"node num = "<<udf_graph.nodes_.size()<<std::endl;
  std::cout<<"edge num = "<<udf_graph.edges_.size()<<std::endl;
  dataflow::GraphViz<dataflow::UdfGraph> graphviz(udf_graph);
  std::string dot_file = "dataflow_googlene.dot";
  graphviz.GraphToDotFileByEdges(dot_file);
  graphviz.GraphToDotFileByNodes(dot_file);
  //std::cout << graph_def.node_def_size() << std::endl;
  return 0;
}


