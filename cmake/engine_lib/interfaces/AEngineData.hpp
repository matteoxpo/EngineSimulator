#pragma once

struct AEngineData {
  double TEngine;
  double TAir;
  int TRunned;
  inline AEngineData(double _TEngine, double _TAir, int _runnedTime)
      : TEngine(_TEngine), TAir(_TAir), TRunned(_runnedTime) {}

  AEngineData(const AEngineData& other) = default;

  AEngineData(AEngineData&& other) = default;

  AEngineData& operator=(AEngineData&& other) = default;

 protected:
  virtual void dummy() = 0;
};