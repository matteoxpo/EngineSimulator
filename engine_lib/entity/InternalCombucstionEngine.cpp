#include "InternalCombucstionEngine.hpp"

InternalCombucstionEngiene::InternalCombucstionEngiene(
    const InternalCombucstionEngineData& _data)
    : data(_data),
      v(this->data.V[0]),
      m(this->data.M[0]),
      a(this->m / this->data.I),
      index(0) {
  this->type = InternalCombucstion;
}

void InternalCombucstionEngiene::ResetData() {
  this->data.TRunned = 0;
  this->v = this->data.V[0];
  this->m = this->data.M[0];
  this->a = this->m / this->data.I;
  this->index = 0;
}

double InternalCombucstionEngiene::CalcEnginePower() const {
  return this->data.M[this->index] * this->data.V[this->index] *
         this->powerCoefficient;
}

bool InternalCombucstionEngiene::IsOverheating() const {
  return this->data.TEngine > this->data.T;
}

void InternalCombucstionEngiene::SimulateStep() {
  this->data.TRunned++;
  this->v += this->a;

  if (this->index < this->data.M.size() - 2) {
    this->index += this->v < this->data.M[this->index + 1] ? 0 : 1;
  }

  double up = this->v - this->data.V[this->index];
  double down = this->data.V[this->index + 1] - this->data.V[this->index];
  double factor = this->data.M[index + 1] - this->data.M[this->index];
  this->m = up / down * factor + this->data.M[this->index];
  this->data.TEngine += this->FindVc() + this->FindVh(this->index);
  this->a = this->m / this->data.I;
  this->data.EnginePower = this->CalcEnginePower();
}

AEngineData* InternalCombucstionEngiene::GetEngineData() const {
  return new InternalCombucstionEngineData(this->data);
}

void InternalCombucstionEngiene::SimulateTime(double time) {
  this->ResetData();

  while (this->data.TRunned < time) {
    this->SimulateStep();
  }
}

double InternalCombucstionEngiene::FindVc() const {
  return this->data.C * (this->data.TAir - this->data.TEngine);
}

double InternalCombucstionEngiene::FindVh(const int& index) const {
  return this->data.M[index] * this->data.Hm +
         this->data.V[index] * this->data.V[index] * this->data.Hv;
}

void InternalCombucstionEngiene::SimulateStep(double& v, double& m, double& a,
                                              long unsigned int& index) {}
