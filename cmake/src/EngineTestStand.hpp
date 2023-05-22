#pragma once

#include <memory>
#include <optional>

#include "EngineModel.hpp"

class EngineTestStand {
 private:
  std::shared_ptr<AEngine> engine;

 public:
  EngineTestStand(const std::shared_ptr<AEngine> &_engine);

  std::optional<AEngineData> RunTest(SimulationWorkingMode mode, double t = -1,
                                     std::optional<std::ofstream> outputStream);
};
