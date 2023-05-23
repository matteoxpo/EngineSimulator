#pragma once

struct AEngineData {
  double TEngine;
  double TAir;
  int TRunned;
  double EnginePower;
  inline AEngineData(double _TEngine, double _TAir, int _runnedTime)
      : TEngine(_TEngine), TAir(_TAir), TRunned(_runnedTime) {}

  // AEngineData() = default;
  AEngineData(const AEngineData& other) = default;

  AEngineData(AEngineData&& other) = default;

  AEngineData& operator=(AEngineData&& other) = default;

 protected:
  virtual void dummy() const = 0;
};