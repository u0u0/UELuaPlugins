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
#include "Materials/MaterialInstanceDynamic.h"


// expend func for MaterialInstanceDynamic which not be mark as UFUNCTION
// need use BEGIN_EXPORT_REFLECTED_CLASS
BEGIN_EXPORT_REFLECTED_CLASS(UMaterialInstanceDynamic)
    // static functions
    ADD_EXTERNAL_FUNCTION_EX("Create", UMaterialInstanceDynamic*, UMaterialInstanceDynamic::Create, class UMaterialInterface*, class UObject*, FName)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(UMaterialInstanceDynamic)
