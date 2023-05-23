#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "InternalCombucstionEngineData.hpp"

class AEngineDataSerializer {
 protected:
  boost::property_tree::ptree serialize_pt;
  boost::property_tree::ptree deserialize_pt;

 public:
  AEngineDataSerializer() = default;
  AEngineDataSerializer(const AEngineDataSerializer& other) = delete;
  AEngineDataSerializer(AEngineDataSerializer&& other) = default;

  inline void SetDeserializePt(boost::property_tree::ptree&& _deserialize_pt) {
    this->deserialize_pt = _deserialize_pt;
  }
  inline void SetSerializePt(boost::property_tree::ptree&& _serialize_pt) {
    this->serialize_pt = _serialize_pt;
  }

  virtual void SetData(AEngineData* _data) = 0;

  virtual std::unique_ptr<AEngineDataSerializer> CreateInstance(
      boost::property_tree::ptree&& _deserialize_pt,
      boost::property_tree::ptree&& _serialize_pt) = 0;

  virtual void serialize(std::string fileName) = 0;
  virtual AEngineData* deserialize() = 0;
};