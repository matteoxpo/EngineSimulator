#pragma once
#include <fstream>
#include <memory>

#include "AEngineData.hpp"
#include "EngineType.hpp"
#include "InternalCombucstionEngineData.hpp"

class AEngineDataSerializer {
 protected:
  std::ostream* outputStream;
  inline virtual void dummy() = 0;

 public:
  inline AEngineDataSerializer(std::ostream* _outputStream)
      : outputStream(_outputStream) {}
  inline virtual void Serialize(EngineType type,
                                std::shared_ptr<AEngineData> data) {}
  inline virtual void Serialize(
      std::shared_ptr<InternalCombucstionEngineData> data) {}
};
