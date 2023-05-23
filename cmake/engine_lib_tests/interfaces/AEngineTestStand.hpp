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
  std::shared_ptr<AEngineDataSerializer> seriazlier;

 public:
  inline AEngineTestStand(std::unique_ptr<AEngine>& _engine,
                          std::shared_ptr<AEngineDataSerializer> _serializer)
      : engine(_engine.release()), seriazlier(_serializer) {}

  virtual void RunTest(EngineTestType mode, double t = -1) = 0;
};
