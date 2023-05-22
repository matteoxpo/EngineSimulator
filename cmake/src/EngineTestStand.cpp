#include "EngineTestStand.hpp"

EngineTestStand::EngineTestStand(const std::shared_ptr<AEngine>& _engine)
    : engine(_engine) {}

std::optional<AEngineData> EngineTestStand::RunTest(
    SimulationWorkingMode mode, double t,
    std::optional<std::ofstream> outputStream) {
  return std::optional<AEngineData>();
}
