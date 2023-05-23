#include "InternalCombucstionEngineDataSerializer.hpp"

InternalCombucstionEngineDataSerializer::
    InternalCombucstionEngineDataSerializer()
    : AEngineDataSerializer(), InternalCombucstionEngineData() {}

void InternalCombucstionEngineDataSerializer::serialize() {
  this->serialize_pt.put("TEngine", this->TEngine);
  this->serialize_pt.put("TAir", this->TAir);
  this->serialize_pt.put("TRunned", this->TRunned);
  this->serialize_pt.put("EnginePower", this->EnginePower);

  this->serialize_pt.put("T", this->T);
  this->serialize_pt.put("Hm", this->Hm);
  this->serialize_pt.put("Hv", this->Hv);
  this->serialize_pt.put("C", this->C);

  boost::property_tree::ptree mArray, vArray;
  for (const auto& val : this->M) {
    boost::property_tree::ptree element;
    element.put("", val);
    mArray.push_back(std::make_pair("", element));
  }
  for (const auto& val : this->V) {
    boost::property_tree::ptree element;
    element.put("", val);
    vArray.push_back(std::make_pair("", element));
  }
  this->serialize_pt.add_child("M", mArray);
  this->serialize_pt.add_child("V", vArray);
}

void InternalCombucstionEngineDataSerializer::deserialize() {
  this->TEngine = this->deserialize_pt.get<double>("TEngine");
  this->TAir = this->deserialize_pt.get<double>("TAir");
  this->TRunned = this->deserialize_pt.get<bool>("TRunned");
  this->EnginePower = this->deserialize_pt.get<double>("EnginePower");

  this->T = this->deserialize_pt.get<double>("T");
  this->Hm = this->deserialize_pt.get<double>("Hm");
  this->Hv = this->deserialize_pt.get<double>("Hv");
  this->C = this->deserialize_pt.get<double>("C");

  boost::property_tree::ptree mArray = this->deserialize_pt.get_child("M");
  boost::property_tree::ptree vArray = this->deserialize_pt.get_child("V");

  this->M.clear();
  for (const auto& entry : mArray) {
    double val = entry.second.get_value<double>();
    this->M.push_back(val);
  }

  this->V.clear();
  for (const auto& entry : vArray) {
    double val = entry.second.get_value<double>();
    this->V.push_back(val);
  }
}

InternalCombucstionEngineDataSerializer*
InternalCombucstionEngineDataSerializer::CreateInstance(
    boost::property_tree::ptree&& _deserialize_pt,
    boost::property_tree::ptree&& _serialize_pt) {
  InternalCombucstionEngineDataSerializer* instance =
      new InternalCombucstionEngineDataSerializer();

  instance->SetDeserializePt(std::move(_deserialize_pt));
  instance->SetSerializePt(std::move(_serialize_pt));
  return instance;
}
