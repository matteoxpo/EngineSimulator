#pragma once
#include "../entity/EngineType.hpp"
#include "../entity/EngineWorkingMode.hpp"
#include "AEngineData.hpp"

class AEngine {
 protected:
  EngineType type;

 public:
  inline EngineType getType() { return this->type; }
  virtual AEngineData* StartSimulation(SimulationWorkingMode mode,
                                       double time = -1) = 0;
};
