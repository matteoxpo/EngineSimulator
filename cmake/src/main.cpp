#include <cmath>
#include <iostream>
#include <typeinfo>
#include <vector>

// #include "EngineModel.hpp"
#include "AEngine.hpp"
#include "EngineTestStand.hpp"
#include "InternalCombucstionEngine.hpp"
#include "InternalCombucstionEngineDataSerializer.hpp"

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

  std::unique_ptr<AEngine> engine =
      std::make_unique<InternalCombucstionEngiene>(data);

  std::shared_ptr<AEngineDataSerializer> serializer =
      std::make_shared<InternalCombucstionEngineDataSerializer>(&std::cout);

  EngineTestStand stand(engine, serializer);
  auto x = stand.RunTest(UntilOverheating);

  return 0;
}