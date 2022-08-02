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

#include "UELuaPb.h"
#include "LuaEnv.h"

// lua-protobuf
int luaopen_pb(lua_State* L);

void FLuapbModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    Handle = UnLua::FLuaEnv::OnCreated.AddStatic(&FLuapbModule::OnLuaEnvCreated);
}

void FLuapbModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
    UnLua::FLuaEnv::OnCreated.Remove(Handle);
}

void FLuapbModule::OnLuaEnvCreated(UnLua::FLuaEnv& Env)
{
    Env.AddBuiltInLoader(TEXT("pb"), luaopen_pb);
}

IMPLEMENT_MODULE(FLuapbModule, UELuaPb)
