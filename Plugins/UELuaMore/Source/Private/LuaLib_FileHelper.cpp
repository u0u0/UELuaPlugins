// Copyright (c) 2022 u0u0 (http://tyrantek.com/)
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#include "UnLuaCompatibility.h"
#include "UnLuaEx.h"
#include "Misc/FileHelper.h" // read file or write file


static int FileHelper_LoadFileToString(lua_State *L)
{
    // get param from lua
    const char* path = lua_tostring(L, 1);
    // load binary
    TArray<uint8> Data;
    if (FFileHelper::LoadFileToArray(Data, UTF8_TO_TCHAR(path), FILEREAD_Silent)) {
        lua_pushlstring(L, (const char *)Data.GetData(), (size_t)Data.Num());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int FileHelper_SaveStringToFile(lua_State *L)
{
    // get param from lua
    const char* bin = lua_tostring(L, 1);
    lua_Integer length = luaL_len(L, 1);
    const char* path = lua_tostring(L, 2);
    // save binary
    TArray<uint8> Data((uint8*)bin, length);
    if (FFileHelper::SaveArrayToFile(Data, UTF8_TO_TCHAR(path))) {
        lua_pushboolean(L, 1);
    } else {
        lua_pushboolean(L, 0);
    }
    return 1;
}

BEGIN_EXPORT_CLASS(FFileHelper)
    // static functions
    Class->AddStaticCFunction("LoadFileToString", FileHelper_LoadFileToString);
    Class->AddStaticCFunction("SaveStringToFile", FileHelper_SaveStringToFile);
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(FFileHelper)
