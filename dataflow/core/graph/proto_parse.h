/*
 * proto_parse.h
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PROTO_PARSE_H
#define PROTO_PARSE_H
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>

namespace dataflow{
using namespace google::protobuf;
using namespace google::protobuf::io;

class PbParse{
 public:
  PbParse() {}
  ~PbParse() {}

  google::protobuf::Message* CreateMessage(const std::string& type_name);

};


}

#endif /* !PROTO_PARSE_H */
