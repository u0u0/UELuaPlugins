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


BEGIN_EXPORT_CLASS(FBase64)
	// 	static FString Encode(const FString& Source);
	ADD_STATIC_FUNCTION_EX("Encode", FString, Encode, const FString&)
	// 	static bool Decode(const FString& Source, FString& OutDest);
	ADD_STATIC_FUNCTION_EX("Decode", bool, Decode, const FString&, FString&)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(FBase64)