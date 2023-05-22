#pragma once

#include "../interfaces/AEngineDataSerializer.hpp"
class InternalCombucstionEngineDataSerializer : public AEngineDataSerializer {
 private:
  void dummy() override;

 public:
  InternalCombucstionEngineDataSerializer(std::ostream* _outputStream);

  void Serialize(std::shared_ptr<InternalCombucstionEngineData> data) override;
};