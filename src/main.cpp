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
  // double I = 10;
  // std::vector<double> M = {20, 75, 100, 105, 75, 0};
  // std::vector<double> V = {0, 75, 150, 200, 250, 300};
  // double T = 110;
  // double Hm = 0.01;
  // double Hv = 0.0001;
  // double C = 0.1;
  // double TEngine = 20;
  // double TAir = 20;
  // InternalCombucstionEngineData data(I, M, V, T, Hm, Hv, C, TEngine, TAir);

  // std::unique_ptr<AEngine> engine =
  //     std::make_unique<InternalCombucstionEngiene>(data);

  // std::shared_ptr<AEngineDataSerializer> serializer =
  //     std::make_shared<InternalCombucstionEngineDataSerializer>(&std::cout);

  // EngineTestStand stand(engine, serializer);

  // return 0;
}

// #include <boost/property_tree/json_parser.hpp>
// #include <boost/property_tree/ptree.hpp>
// #include <iostream>

// int main() {
//   // Создание пустого объекта property_tree
//   boost::property_tree::ptree pt;

//   // Добавление данных в property_tree
//   pt.put("name", "John Doe");
//   pt.put("age", 30);
//   pt.put("email", "johndoe@example.com");

//   // Сериализация в формат JSON
//   std::ostringstream oss;
//   boost::property_tree::json_parser::write_json("data.json", pt);

//   // Вывод сериализованных данных
//   std::cout << oss.str() << std::endl;

//   // Десериализация из формата JSON
//   std::istringstream iss(oss.str());
//   boost::property_tree::ptree pt2;
//   boost::property_tree::json_parser::read_json(iss, pt2);

//   // Получение данных из property_tree
//   std::string name = pt2.get<std::string>("name");
//   int age = pt2.get<int>("age");
//   std::string email = pt2.get<std::string>("email");

//   // Вывод полученных данных
//   std::cout << "Name: " << name << std::endl;
//   std::cout << "Age: " << age << std::endl;
//   std::cout << "Email: " << email << std::endl;

//   return 0;
// }