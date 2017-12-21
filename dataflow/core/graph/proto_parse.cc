/*
 * proto_parse.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/graph/proto_parse.h"

namespace dataflow{

Message* CreateMessage(const std::string& type_name) {
  Message* message = NULL;
  const Descriptor* descriptor =
    DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
  if (descriptor) {
    const Message* proto_type = 
      MessageFactory::generated_factory()->GetPrototype(descriptor);
    if (proto_type) {
      message = proto_type->New();
    }
  }
  return message;
}

}



