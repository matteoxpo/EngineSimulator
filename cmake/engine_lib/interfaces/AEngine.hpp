#pragma once
#include "../entity/EngineType.hpp"
#include "AEngineData.hpp"

class AEngine {
 protected:
  EngineType type;

 public:
  inline EngineType getType() const { return this->type; }
  virtual void SimulateTime(double time = -1) = 0;
  virtual void SimulateStep() = 0;
  virtual double CalcEnginePower() const = 0;
  virtual AEngineData* GetEngineData() const = 0;
  virtual bool IsOverheating() const = 0;
  virtual void ResetData() = 0;
};
