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

using System;
using System.IO;
using UnrealBuildTool;

public class UELuaMore : ModuleRules
{
	public UELuaMore(ReadOnlyTargetRules Target) : base(Target)
	{
		bEnforceIWYU = false;
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bUseUnity = false;
		bEnableUndefinedIdentifierWarnings = false;

		PublicDependencyModuleNames.AddRange(new string[]
				{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				});

		PrivateDependencyModuleNames.AddRange(new string[]
				{
				"UnLua",
				"Lua",
				});
	}
}
