// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include <PugiXml/pugixml.hpp>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace pugi;

namespace SourceData
{
    // All classes and structs
    extern unordered_map<string, xml_node> classesByID_; // id -> compounddef

    // All classes and structs from Urho3D namepace
    extern unordered_map<string, xml_node> classesByName_; // name -> compounddef

    // Huge table with all members of all classes and structs
    extern unordered_map<string, xml_node> members_; // id -> memberdef

    // All enums from Urho3D namepace
    extern unordered_map<string, xml_node> enums_; // name -> memberdef

    // List of all defines. Used to detect that some function is a define actually
    extern vector<string> defines_;

    // Namespace Urho3D contains enums, global functions and global variables
    extern xml_node namespaceUrho3D_; // compounddef from file namespace_urho3_d.xml

    // All usings from namespace Dviglo
    extern vector<xml_node> usings_; // memberdefs

    // Header files with @nobindfile mark at the beginning
    extern vector<string> ignoredHeaders_;

    // Init all variables above
    void LoadAllXmls(const string& dir);
}
