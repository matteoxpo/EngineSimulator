#include <cmath>
#include <iostream>
#include <typeinfo>
#include <vector>

// #include "EngineModel.hpp"
#include <exception>

#include "AEngine.hpp"
#include "EngineTestStand.hpp"
#include "InternalCombucstionEngine.hpp"
#include "InternalCombucstionEngineDataSerializer.hpp"
int main() {
  double TAir;
  while (true) {
    try {
      std::cout << "Введите температуру воздуха вокруг: ";
      std::cin >> TAir;
      break;
    } catch (std::exception& ex) {
      std::cout << "Ошибка ввода\n";
    }
  }

  boost::property_tree::ptree deserialize_pt;

  std::ifstream file(
      "/home/xpomin/Prog/EngineSimulator/engine_lib_tests/test_data/"
      "Read.json");

  if (file.is_open()) {
    boost::property_tree::json_parser::read_json(file, deserialize_pt);
    file.close();
  } else {
    throw std::runtime_error("Filed to open configire JSON file");
  }

  AEngineDataSerializer* baseSerializer =
      new InternalCombucstionEngineDataSerializer();

  boost::property_tree::ptree serialize_pt;
  auto serializer = baseSerializer->CreateInstance(std::move(deserialize_pt),
                                                   std::move(serialize_pt));
  auto x =
      dynamic_cast<InternalCombucstionEngineData*>(serializer->deserialize());

  x->TAir = TAir;

  std::unique_ptr<AEngine> engine =
      std::make_unique<InternalCombucstionEngiene>(x);

  auto stand =
      std::make_shared<EngineTestStand>(EngineTestStand(engine, serializer));

  stand->RunTest(SimulateToTime,
                 "/home/xpomin/Prog/EngineSimulator/engine_lib_tests/test_data/"
                 "Write.json",
                 false, 100);

  return 0;
}