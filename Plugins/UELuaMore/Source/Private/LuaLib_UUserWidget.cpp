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
#include "Blueprint/UserWidget.h"


static int32 UUserWidget_GetWidgetFromName(lua_State* L)
{
    UUserWidget* V = (UUserWidget*)GetCppInstanceFast(L, 1);
    if (!V) {
        UE_LOG(LogUnLua, Log, TEXT("%s: Invalid UUserWidget!"), ANSI_TO_TCHAR(__FUNCTION__));
        return 0;
    }
    
    // get param from lua
    const char* str = lua_tostring(L, 2);
    FName Name = FName(UTF8_TO_TCHAR(str));
    UWidget * Widget = V->GetWidgetFromName(Name);
    UnLua::PushUObject(L, Widget);
    return 1;
}

static const luaL_Reg UUserWidgetLib[] =
{
    {"GetWidgetFromName", UUserWidget_GetWidgetFromName},
    { nullptr, nullptr }
};

// expend func UUserWidget which not be mark as UFUNCTION
// need use BEGIN_EXPORT_REFLECTED_CLASS
BEGIN_EXPORT_REFLECTED_CLASS(UUserWidget)
    ADD_LIB(UUserWidgetLib)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(UUserWidget)
