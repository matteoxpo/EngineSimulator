#pragma once

#include <fstream>
#include <memory>
#include <optional>

#include "../interfaces/AEngineDataSerializer.hpp"
#include "../interfaces/AEngineTestStand.hpp"
#include "AEngine.hpp"
#include "EngineModel.hpp"

class EngineTestStand : public AEngineTestStand {
 private:
 public:
  EngineTestStand(std::unique_ptr<AEngine>& _engine,
                  std::unique_ptr<AEngineDataSerializer>& _serializer);
  std::optional<std::shared_ptr<AEngineData>> RunTest(
      EngineTestType testType, std::string fileName, bool returnData = false,
      double time = -1) override;
};
