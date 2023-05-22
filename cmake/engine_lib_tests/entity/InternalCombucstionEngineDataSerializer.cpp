#include "InternalCombucstionEngineDataSerializer.hpp"

void InternalCombucstionEngineDataSerializer::dummy() {}

InternalCombucstionEngineDataSerializer::
    InternalCombucstionEngineDataSerializer(std::ostream* _outputStream)
    : AEngineDataSerializer(_outputStream) {}

void InternalCombucstionEngineDataSerializer::Serialize(
    std::shared_ptr<InternalCombucstionEngineData> data) {
  if (this->outputStream) {
    *(this->outputStream) << data->TRunned << '\n';
  }
}