#pragma once

#include "il2cpp.hpp"


namespace myosotis::testmod {
// JSON NODE AND OTHER JSON STUFF

inline il2cpp::Il2CppClass* jsonSerializerClass = nullptr;
inline il2cpp::Il2CppMethod* jsonSerializer_Serialize = nullptr;

inline il2cpp::Il2CppClass* csJsonNodeListClass = nullptr;
inline il2cpp::Il2CppMethod* csJsonNodeList_Add = nullptr;
inline il2cpp::Il2CppMethod* csJsonNodeList_getItem = nullptr;
inline il2cpp::Il2CppMethod* csJsonNodeList_getCount = nullptr;

inline il2cpp::Il2CppClass* jsonNodeClass = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_Parse = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_Add1 = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_Add2 = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_getItemIndex = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_getItemKey = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_getCount = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_getAsInt = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_ToString = nullptr;
inline il2cpp::Il2CppMethod* jsonNode_getAsByteList = nullptr;

inline il2cpp::Il2CppClass* stringStaticDataJsonClass = nullptr;
inline il2cpp::Il2CppMethod* stringStaticDataJson_ctor = nullptr;
inline il2cpp::Il2CppMethod* stringStaticDataJson_GetDataClass = nullptr;
inline il2cpp::Il2CppMethod* stringStaticDataJson_GetCount = nullptr;
inline il2cpp::Il2CppMethod* stringStaticDataJson_GetDataByIndex = nullptr;
inline il2cpp::Il2CppMethod* stringStaticDataJson_AddData = nullptr;

inline il2cpp::Il2CppClass* jsonArrayClass = nullptr;
inline il2cpp::Il2CppMethod* jsonArray_getCount = nullptr;

inline il2cpp::Il2CppClass* jsonObjectClass = nullptr;

void init_json(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* jsonImg);

}