#pragma once

struct AEngineData {
  // температура двигателя
  double TEngine;
  // температура воздуха
  double TAir;
  // смоделированное время
  int TRunned;
  inline AEngineData(double _TEngine, double _TAir, int _runnedTime)
      : TEngine(_TEngine), TAir(_TAir), TRunned(_runnedTime) {}

  AEngineData(const AEngineData& other) = default;

  AEngineData(AEngineData&& other) = default;

  AEngineData& operator=(AEngineData&& other) = default;

 private:
  virtual void dummy() {}
};