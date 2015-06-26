
#pragma once

#include <cstdint>

namespace base
{
    class JsonWriterFile;
}

class DemoFileReader;
class DemoFileWriter;
class DemoFileReader2;
class DemoFileWriter2;

using FileRead = DemoFileReader;
using FileWrite = DemoFileWriter;
class JsonRead;
using JsonWrite = base::JsonWriterFile;

#define DECLARE_DEM_HANDLERS(msgname) \
    namespace DemHandlers \
    { \
        bool msgname##_FileRead_Internal(FileRead& demofile, DemMsg::msgname* data); \
        bool msgname##_FileWrite_Internal(FileWrite& demofile, DemMsg::msgname* data); \
        bool msgname##_JsonRead_Internal(JsonRead& jsonbuf, DemMsg::msgname* data); \
        bool msgname##_JsonWrite_Internal(JsonWrite& jsonbuf, DemMsg::msgname* data); \
        inline bool msgname##_FileRead(FileRead& demofile, void* data) \
        { \
            return msgname##_FileRead_Internal(demofile, reinterpret_cast<DemMsg::msgname*>(data)); \
        } \
        inline bool msgname##_FileWrite(FileWrite& demofile, void* data) \
        { \
            return msgname##_FileWrite_Internal(demofile, reinterpret_cast<DemMsg::msgname*>(data)); \
        } \
        inline bool msgname##_JsonRead(JsonRead& jsonbuf, void* data) \
        { \
            return msgname##_JsonRead_Internal(jsonbuf, reinterpret_cast<DemMsg::msgname*>(data)); \
        } \
        inline bool msgname##_JsonWrite(JsonWrite& jsonbuf, void* data) \
        { \
            return msgname##_JsonWrite_Internal(jsonbuf, reinterpret_cast<DemMsg::msgname*>(data)); \
        } \
    }

namespace DemHandlers
{
    bool DemMsg_FileRead(uint32_t type, FileRead& demofile, void* data);
    bool DemMsg_FileWrite(uint32_t type, FileWrite& demofile, void* data);
    bool DemMsg_JsonRead(uint32_t type, JsonRead& jsonbuf, void* data);
    bool DemMsg_JsonWrite(uint32_t type, JsonWrite& jsonbuf, void* data);
}
