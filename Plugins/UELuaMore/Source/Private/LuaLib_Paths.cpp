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
#include "Misc/Paths.h"

static FString FPaths_ConvertRelativePathToFull1(const FString& InPath)
{
    return FPaths::ConvertRelativePathToFull(InPath);
}

static FString FPaths_ConvertRelativePathToFull2(const FString& BasePath, const FString& InPath)
{
    return FPaths::ConvertRelativePathToFull(BasePath, InPath);
}

static FString FPaths_Combine2(const FString& Path1, const FString& Path2)
{
    return FPaths::Combine(Path1, Path2);
}

static FString FPaths_Combine3(const FString& Path1, const FString& Path2, const FString& Path3)
{
    return FPaths::Combine(Path1, Path2, Path3);
}

BEGIN_EXPORT_CLASS(FPaths)
    // static functions
    ADD_EXTERNAL_FUNCTION_EX("ConvertRelativePathToFull1", FString, FPaths_ConvertRelativePathToFull1, const FString&)
    ADD_EXTERNAL_FUNCTION_EX("ConvertRelativePathToFull2", FString, FPaths_ConvertRelativePathToFull2, const FString&, const FString&)
    ADD_EXTERNAL_FUNCTION_EX("Combine2", FString, FPaths_Combine2, const FString&, const FString&)
    ADD_EXTERNAL_FUNCTION_EX("Combine3", FString, FPaths_Combine3, const FString&, const FString&, const FString&)
    ADD_STATIC_FUNCTION(DirectoryExists)
    ADD_STATIC_FUNCTION(FileExists)
    ADD_STATIC_FUNCTION(ProjectContentDir)
    ADD_STATIC_FUNCTION(ProjectPersistentDownloadDir)
    ADD_STATIC_FUNCTION(Split)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(FPaths)
