#pragma once
#include <memory>
#include <vector>

#include "../interfaces/AEngine.hpp"
#include "EngineType.hpp"
#include "InternalCombucstionEngineData.hpp"

class InternalCombucstionEngiene : public AEngine {
 private:
  InternalCombucstionEngineData data;
  double FindVc() const;
  double FindVh(const int& index) const;
  void SimulateStep(double& v, double& m, double& a, long unsigned int& index);

  double v;
  double m;
  double a;
  const double powerCoefficient = 0.001;
  long unsigned int index;

 public:
  InternalCombucstionEngiene(const InternalCombucstionEngineData& _data);
  InternalCombucstionEngiene(const InternalCombucstionEngineData* _data);
  void SimulateTime(double time = -1) override;
  void SimulateStep() override;
  AEngineData* GetEngineData() const override;
  virtual bool IsOverheating() const override;
  double CalcEnginePower() const override;
  void ResetData() override;
};
