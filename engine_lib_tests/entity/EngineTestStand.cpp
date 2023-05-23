
#include "EngineTestStand.hpp"

EngineTestStand::EngineTestStand(
    std::unique_ptr<AEngine>& _engine,
    std::shared_ptr<AEngineDataSerializer> _serializer)
    : AEngineTestStand(_engine, _serializer) {
  if (!this->engine) {
    throw std::invalid_argument("EngineTestStand: engine nullptr");
  }
}

std::optional<std::shared_ptr<AEngineData>> EngineTestStand::RunTest(
    EngineTestType testType, double time, bool returnData) {
  this->engine->ResetData();
  switch (testType) {
    case SimulateToTime:
      this->engine->SimulateTime(time);
      break;
    case SimulateUntilOverheating:
      while (!this->engine->IsOverheating()) {
        this->engine->SimulateStep();
      }
    default:
      throw std::invalid_argument("EngineTestStand: RunTest invalid test mode");
      break;
  }

  AEngineData* baseData = this->engine->GetEngineData();
  this->seriazlier->serialize();
  if (returnData) {
    return std::optional<std::shared_ptr<AEngineData>>(baseData);
  }
  delete baseData;
  return std::optional<std::shared_ptr<AEngineData>>();
}