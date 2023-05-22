#pragma once

#include <fstream>
#include <memory>

#include "AEngine.hpp"
#include "AEngineData.hpp"

class ATestStand {
 protected:
  std::unique_ptr<AEngine> engine;

 public:
  inline ATestStand(std::unique_ptr<AEngine>& _engine)
      : engine(_engine.release()) {}

  virtual void RunTest(SimulationWorkingMode mode, double t = -1) = 0;
};
