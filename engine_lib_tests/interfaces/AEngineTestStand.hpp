#pragma once

#include <fstream>
#include <memory>

#include "../EngineTestType.hpp"
#include "AEngine.hpp"
#include "AEngineData.hpp"
#include "AEngineDataSerializer.hpp"

class AEngineTestStand {
 protected:
  std::unique_ptr<AEngine> engine;
  std::unique_ptr<AEngineDataSerializer> seriazlier;

 public:
  inline AEngineTestStand(std::unique_ptr<AEngine>& _engine,
                          std::unique_ptr<AEngineDataSerializer>& _serializer)
      : engine(_engine.release()), seriazlier(_serializer.release()) {
    if (!this->engine) {
      throw std::invalid_argument("EngineTestStand: engine nullptr");
    }
  }

  virtual std::optional<std::shared_ptr<AEngineData>> RunTest(
      EngineTestType testType, std::string fileName, bool returnData,
      double time) = 0;
};
