#include "EngineTestStand.hpp"

#include <exception>
#include <string>

class NotImplementedException : public std::exception {
 public:
  NotImplementedException(const std::string& message) : message_(message) {}

  virtual const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};

EngineTestStand::EngineTestStand(
    std::unique_ptr<AEngine>& _engine,
    std::shared_ptr<AEngineDataSerializer> _serializer)
    : engine(_engine.release()), serializer(_serializer) {
  if (!this->engine) {
    throw std::invalid_argument("EngineTestStand: engine nullptr");
  }
}

std::shared_ptr<AEngineData> EngineTestStand::RunTest(
    SimulationWorkingMode mode, double t) {
  AEngineData* baseData = this->engine->StartSimulation(mode, t);
  std::shared_ptr<InternalCombucstionEngineData> internalData;
  /*
  std::unique_ptr<ElectroEngineData> electroData;
  */
  switch (this->engine->getType()) {
    case Electro:
      throw NotImplementedException("Electro is not implemented");
      break;
    case InternalCombucstion:
    default:
      internalData = std::move(std::shared_ptr<InternalCombucstionEngineData>(
          dynamic_cast<InternalCombucstionEngineData*>(baseData)));
      this->serializer->Serialize(internalData);
      return internalData;
      break;
  }
}
