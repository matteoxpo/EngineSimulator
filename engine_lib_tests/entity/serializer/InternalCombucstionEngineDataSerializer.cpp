#include "InternalCombucstionEngineDataSerializer.hpp"

void InternalCombucstionEngineDataSerializer::SetData(AEngineData* _data) {
  this->data = std::dynamic_pointer_cast<InternalCombucstionEngineData>(
      std::shared_ptr<AEngineData>(_data));
  if (!this->data) {
    throw std::runtime_error(
        "InternalCombucstionEngineDataSerializer: SetData dynamic_pointer_cast "
        "returned nullptr");
  }
}

InternalCombucstionEngineDataSerializer::
    InternalCombucstionEngineDataSerializer()
    : AEngineDataSerializer() {}

void InternalCombucstionEngineDataSerializer::serialize(
    std::basic_ostream<typename std::ostream::char_type>& stream) {
  this->serialize_pt.put("TEngine", this->data->TEngine);
  this->serialize_pt.put("TAir", this->data->TAir);
  this->serialize_pt.put("TRunned", this->data->TRunned);
  this->serialize_pt.put("EnginePower", this->data->EnginePower);

  this->serialize_pt.put("T", this->data->T);
  this->serialize_pt.put("Hm", this->data->Hm);
  this->serialize_pt.put("Hv", this->data->Hv);
  this->serialize_pt.put("C", this->data->C);

  boost::property_tree::ptree mArray, vArray;
  for (const auto& val : this->data->M) {
    boost::property_tree::ptree element;
    element.put("", val);
    mArray.push_back(std::make_pair("", element));
  }
  for (const auto& val : this->data->V) {
    boost::property_tree::ptree element;
    element.put("", val);
    vArray.push_back(std::make_pair("", element));
  }
  this->serialize_pt.add_child("M", mArray);
  this->serialize_pt.add_child("V", vArray);

  boost::property_tree::write_json(stream, this->serialize_pt);
}

void InternalCombucstionEngineDataSerializer::deserialize() {
  this->data->TEngine = this->deserialize_pt.get<double>("TEngine");
  this->data->TAir = this->deserialize_pt.get<double>("TAir");
  this->data->TRunned = this->deserialize_pt.get<bool>("TRunned");
  this->data->EnginePower = this->deserialize_pt.get<double>("EnginePower");

  this->data->T = this->deserialize_pt.get<double>("T");
  this->data->Hm = this->deserialize_pt.get<double>("Hm");
  this->data->Hv = this->deserialize_pt.get<double>("Hv");
  this->data->C = this->deserialize_pt.get<double>("C");
  boost::property_tree::ptree mArray = this->deserialize_pt.get_child("M");
  boost::property_tree::ptree vArray = this->deserialize_pt.get_child("V");

  this->data->M.clear();
  for (const auto& entry : mArray) {
    double val = entry.second.get_value<double>();
    this->data->M.push_back(val);
  }

  this->data->V.clear();
  for (const auto& entry : vArray) {
    double val = entry.second.get_value<double>();
    this->data->V.push_back(val);
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
