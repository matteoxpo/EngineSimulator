#pragma once
#include <cmath>
#include <vector>

#include "../interfaces/AEngine.hpp"
#include "EngineType.hpp"
#include "EngineWorkingMode.hpp"
#include "InternalCombucstionEngineData.hpp"

class InternalCombucstionEngiene : public AEngine {
 private:
  InternalCombucstionEngineData data;
  double FindVc();
  double FindVh(const int& index);
  void SimulateStep(double& v, double& m, double& a, long unsigned int& index);

 public:
  InternalCombucstionEngiene(const InternalCombucstionEngineData& _data);
  AEngineData StartSimulation(SimulationWorkingMode mode,
                              double time = -1) override;
};
