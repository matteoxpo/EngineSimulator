
#include "EngineTestStand.hpp"

EngineTestStand::EngineTestStand(
    std::unique_ptr<AEngine>& _engine,
    std::unique_ptr<AEngineDataSerializer>& _serializer)
    : AEngineTestStand(_engine, _serializer) {}

std::optional<std::shared_ptr<AEngineData>> EngineTestStand::RunTest(
    EngineTestType testType, std::string fileName, bool returnData,
    double time) {
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
  this->seriazlier->SetData(baseData);

  this->seriazlier->serialize(fileName);

  if (returnData) {
    return std::optional<std::shared_ptr<AEngineData>>(baseData);
  }
  delete baseData;
  return std::optional<std::shared_ptr<AEngineData>>();
}