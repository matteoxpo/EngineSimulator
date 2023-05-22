#include "InternalCombucstionEngine.hpp"

#include <iostream>

InternalCombucstionEngiene::InternalCombucstionEngiene(
    const InternalCombucstionEngineData& _data)
    : data(_data) {}

AEngineData InternalCombucstionEngiene::StartSimulation(
    SimulationWorkingMode mode, double time) {
  double v = this->data.V[0];
  double m = this->data.M[0];
  double a = m / this->data.I;
  long unsigned int index = 0;

  switch (mode) {
    case UntilOverheating:
      while (this->data.TRunned < this->data.T) {
        this->SimulateStep(a, m, v, index);
      }
      break;

    default:
    case ToTime:
      while (this->data.TRunned < time) {
        this->SimulateStep(a, m, v, index);
      }
      break;
  }
  return (InternalCombucstionEngineData(this->data));
}

double InternalCombucstionEngiene::FindVc() {
  return this->data.C * (this->data.TAir - this->data.TEngine);
}

double InternalCombucstionEngiene::FindVh(const int& index) {
  return this->data.M[index] * this->data.Hm +
         pow(this->data.V[index], 2) * this->data.Hv;
}

void InternalCombucstionEngiene::SimulateStep(double& v, double& m, double& a,
                                              long unsigned int& index) {
  this->data.TRunned++;
  v += a;

  if (index < this->data.M.size() - 2) {
    index += v < this->data.M[index + 1] ? 0 : 1;
  }

  double up = v - this->data.V[index];
  double down = this->data.V[index + 1] - this->data.V[index];
  double factor = this->data.M[index + 1] - this->data.M[index];
  m = up / down * factor + this->data.M[index];
  this->data.TEngine += this->FindVc() + this->FindVh(index);
  a = m / this->data.I;
}
