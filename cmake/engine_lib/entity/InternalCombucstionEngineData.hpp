#pragma once
#include <vector>

#include "../interfaces/AEngineData.hpp"
struct InternalCombucstionEngineData : public AEngineData {
  double I;
  // Кусочно-линейная зависимость крутящего момента, вырабатываемого двигателем
  std::vector<double> M;
  // Cкорость вращения коленвала
  std::vector<double> V;
  // Температура перегрева
  double T;
  // Коэффициент зависимости скорости нагрева от крутящего момент
  double Hm;
  // Коэффициент зависимости скорости нагрева от скорости вращения коленвала
  double Hv;
  // Коэффициент зависимости скорости охлаждения от температуры двигателя и
  // окружающей среды
  double C;
  InternalCombucstionEngineData(const double& _I, const std::vector<double>& _M,
                                std::vector<double>& _V, const double& _T,
                                const double& _Hm, const double& _Hv,
                                double& _C, const double& _TEngine,
                                const double& _TAir);
  InternalCombucstionEngineData(const InternalCombucstionEngineData& other);
  InternalCombucstionEngineData(const InternalCombucstionEngineData&& other);
  InternalCombucstionEngineData() = default;
};