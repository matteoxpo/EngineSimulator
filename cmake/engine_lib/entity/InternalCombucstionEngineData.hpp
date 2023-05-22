#pragma once
#include <vector>

#include "../interfaces/AEngineData.hpp"
struct InternalCombucstionEngineData : public AEngineData {
  double I;
  std::vector<double> M;
  std::vector<double> V;
  double T;
  double Hm;
  double Hv;
  double C;
  InternalCombucstionEngineData(const double& _I, const std::vector<double>& _M,
                                std::vector<double>& _V, const double& _T,
                                const double& _Hm, const double& _Hv,
                                double& _C, const double& _TEngine,
                                const double& _TAir);
  InternalCombucstionEngineData(const InternalCombucstionEngineData& other);
  InternalCombucstionEngineData(const InternalCombucstionEngineData&& other);
  InternalCombucstionEngineData() = default;

 private:
  inline void dummy() override {}
};