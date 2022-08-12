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
#include "HAL/FileManager.h"


// Unlua cannot use referenced return value, so need wapper to point
static IFileManager* IFileManager_Get()
{
    return &IFileManager::Get();
}

static int32 IFileManager_FileExists(lua_State* L)
{
    IFileManager* V = (IFileManager*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid IFileManager!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* path = lua_tostring(L, 2);
    lua_pushboolean(L, V->FileExists(UTF8_TO_TCHAR(path)));
    return 1;
}

static int32 IFileManager_DirectoryExists(lua_State* L)
{
    IFileManager* V = (IFileManager*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid IFileManager!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* path = lua_tostring(L, 2);
    lua_pushboolean(L, V->DirectoryExists(UTF8_TO_TCHAR(path)));
    return 1;
}

// MakeDirectory(path, tree)
static int32 IFileManager_MakeDirectory(lua_State* L)
{
    IFileManager* V = (IFileManager*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid IFileManager!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* path = lua_tostring(L, 2);
    if (lua_isboolean(L, 3)) {
        lua_pushboolean(L, V->MakeDirectory(UTF8_TO_TCHAR(path), lua_toboolean(L, 3)));
    } else {
        lua_pushboolean(L, V->MakeDirectory(UTF8_TO_TCHAR(path)));
    }
    return 1;
}

// DeleteDirectory(path, tree)
static int32 IFileManager_DeleteDirectory(lua_State* L)
{
    IFileManager* V = (IFileManager*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid IFileManager!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* path = lua_tostring(L, 2);
    if (lua_isboolean(L, 3)) {
        lua_pushboolean(L, V->DeleteDirectory(UTF8_TO_TCHAR(path), 0, lua_toboolean(L, 3)));
    } else {
        lua_pushboolean(L, V->DeleteDirectory(UTF8_TO_TCHAR(path)));
    }
    return 1;
}

static int32 IFileManager_Delete(lua_State* L)
{
    IFileManager* V = (IFileManager*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid IFileManager!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* path = lua_tostring(L, 2);
    lua_pushboolean(L, V->Delete(UTF8_TO_TCHAR(path)));
    return 1;
}

static const luaL_Reg IFileManagerLib[] =
{
    {"FileExists", IFileManager_FileExists},
    {"DirectoryExists", IFileManager_DirectoryExists},
    {"MakeDirectory", IFileManager_MakeDirectory},
    {"DeleteDirectory", IFileManager_DeleteDirectory},
    {"Delete", IFileManager_Delete},
    {nullptr, nullptr}
};

BEGIN_EXPORT_CLASS(IFileManager)
    // static functions
    ADD_EXTERNAL_FUNCTION_EX("Get", IFileManager*, IFileManager_Get)
    // add member
    ADD_LIB(IFileManagerLib)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(IFileManager)
