#pragma once

#include <boost/property_tree/ptree.hpp>
#include <memory>

#include "../../interfaces/AEngineDataSerializer.hpp"
#include "InternalCombucstionEngineData.hpp"

class InternalCombucstionEngineDataSerializer : public AEngineDataSerializer {
 private:
  std::shared_ptr<InternalCombucstionEngineData> data;

 public:
  void SetData(AEngineData* _data) override;

  InternalCombucstionEngineDataSerializer();
  void serialize(std::string fileName) override;
  AEngineData* deserialize() override;

  std::unique_ptr<AEngineDataSerializer> CreateInstance(
      boost::property_tree::ptree&& _deserialize_pt,
      boost::property_tree::ptree&& _serialize_pt) override;
};