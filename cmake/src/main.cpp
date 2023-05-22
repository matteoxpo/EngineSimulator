#include <cmath>
#include <iostream>
#include <typeinfo>
#include <vector>

// #include "InternalCombucstionEngineData.hpp"
#include "EngineModel.hpp"
int main() {
  double I = 10;
  std::vector<double> M = {20, 75, 100, 105, 75, 0};
  std::vector<double> V = {0, 75, 150, 200, 250, 300};
  double T = 110;
  double Hm = 0.01;
  double Hv = 0.0001;
  double C = 0.1;
  double TEngine = 20;
  double TAir = 20;
  InternalCombucstionEngineData data(I, M, V, T, Hm, Hv, C, TEngine, TAir);
  InternalCombucstionEngiene engine(data);

  AEngineData newdata =
      std::move(engine.StartSimulation(UntilOverheating, 100));
  AEngineData* basePtr = &newdata;

  InternalCombucstionEngineData* derivedPtr =
      static_cast<InternalCombucstionEngineData*>(basePtr);
  if (derivedPtr != nullptr) {
    std::cout << derivedPtr->TRunned;
  } else {
    std::cout << "Failure\n";
  }

  return 0;
}