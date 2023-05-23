#pragma once

#include "../../interfaces/AEngineDataSerializer.hpp"
#include "InternalCombucstionEngineData.hpp"

class InternalCombucstionEngineDataSerializer
    : public AEngineDataSerializer,
      public InternalCombucstionEngineData {
 public:
  InternalCombucstionEngineDataSerializer();
  void serialize() override;
  void deserialize() override;

  InternalCombucstionEngineDataSerializer* CreateInstance(
      boost::property_tree::ptree&& _deserialize_pt,
      boost::property_tree::ptree&& _serialize_pt);
};