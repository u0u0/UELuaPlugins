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
#include "Misc/Base64.h"

static int FBase64_Encode(lua_State *L)
{
    // get param from lua
    const char* bin = lua_tostring(L, 1);
    lua_Integer length = luaL_len(L, 1);
    // encode base64
    FString Out = FBase64::Encode((const uint8*)bin, (uint32)length);
    // return to lua
    lua_pushstring(L, TCHAR_TO_UTF8(*Out));
    return 1;
}

static int FBase64_Decode(lua_State *L)
{
    // get param from lua
    const char* str = lua_tostring(L, 1);
    FString Source = FString(str);
    // decode base64
    TArray<uint8> Data;
    uint32 ExpectedLength = FBase64::GetDecodedDataSize(Source);
    Data.AddZeroed(ExpectedLength);
    if (FBase64::Decode(*Source, Source.Len(), (uint8*)Data.GetData())) {
        lua_pushlstring(L, (const char *)Data.GetData(), (size_t)Data.Num());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

BEGIN_EXPORT_CLASS(FBase64)
    // static function
    Class->AddStaticCFunction("Encode", FBase64_Encode);
    Class->AddStaticCFunction("Decode", FBase64_Decode);
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(FBase64)
