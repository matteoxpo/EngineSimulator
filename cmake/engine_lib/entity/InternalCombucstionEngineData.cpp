#include "InternalCombucstionEngineData.hpp"

InternalCombucstionEngineData::InternalCombucstionEngineData(
    const double& _I, const std::vector<double>& _M, std::vector<double>& _V,
    const double& _T, const double& _Hm, const double& _Hv, double& _C,
    const double& _TEngine, const double& _TAir)
    : AEngineData(_TEngine, _TAir, 0),
      I(_I),
      M(_M),
      V(_V),
      T(_T),
      Hm(_Hm),
      Hv(_Hv),
      C(_C) {}

InternalCombucstionEngineData::InternalCombucstionEngineData(
    const InternalCombucstionEngineData& other)
    : AEngineData(other.TEngine, other.TAir, other.TRunned),
      I(other.I),
      M(other.M),
      V(other.V),
      T(other.T),
      Hm(other.Hm),
      Hv(other.Hv),
      C(other.C) {}

InternalCombucstionEngineData::InternalCombucstionEngineData(
    const InternalCombucstionEngineData&& other)
    : AEngineData(std::move(other)),
      I(other.I),
      M(std::move(other.M)),
      V(std::move(other.V)),
      T(other.T),
      Hm(other.Hm),
      Hv(other.Hv),
      C(other.C) {}
