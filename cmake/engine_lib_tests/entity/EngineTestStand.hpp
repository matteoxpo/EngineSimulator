#pragma once

#include <fstream>
#include <memory>
#include <optional>

#include "../interfaces/AEngineDataSerializer.hpp"
#include "AEngine.hpp"
#include "EngineModel.hpp"

class EngineTestStand {
 private:
  std::unique_ptr<AEngine> engine;
  std::shared_ptr<AEngineDataSerializer> serializer;

 public:
  EngineTestStand(std::unique_ptr<AEngine>& _engine,
                  std::shared_ptr<AEngineDataSerializer> _serializer);

  std::shared_ptr<AEngineData> RunTest(SimulationWorkingMode mode,
                                       double t = -1);
};
