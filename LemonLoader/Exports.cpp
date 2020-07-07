#include "Exports.h"
#include "LemonLoader.h"
#include "Il2Cpp.h"
#include "Mono.h"
#include "HookManager.h"
#include "Logger.h"

void Log(MonoString* txt) { Logger::Log(Mono::mono_string_to_utf8(txt)); }
void LogColor(MonoString* txt, ConsoleColor color) { Logger::Log(Mono::mono_string_to_utf8(txt), color); }
void LogWarning(MonoString* namesection, MonoString* txt) { Logger::LogWarning(Mono::mono_string_to_utf8(namesection), Mono::mono_string_to_utf8(txt)); }
void LogError(MonoString* namesection, MonoString* txt) { Logger::LogError(Mono::mono_string_to_utf8(namesection), Mono::mono_string_to_utf8(txt)); }
void LogDLLError(MonoString* namesection, MonoString* msg) { Logger::LogDLLError(Mono::mono_string_to_utf8(namesection), Mono::mono_string_to_utf8(msg)); }
void LogDLLStatus(ModHandler_DLLStatus type) { Logger::LogDLLStatus(type); }
bool IsIl2CppGame() { return LemonLoader::IsGameIl2Cpp; }
bool IsDebugMode() { return LemonLoader::DebugMode; }
bool IsConsoleEnabled() { return Console::Enabled; }
MonoString* GetGameDirectory() { return Mono::mono_string_new(Mono::Domain, LemonLoader::GamePath); }
MonoString* GetGameDataDirectory() { return Mono::mono_string_new(Mono::Domain, LemonLoader::DataPath); }
void Hook(Il2CppMethod* target, void* detour) { HookManager::Hook(target, detour); }
void Unhook(Il2CppMethod* target, void* detour) { HookManager::Unhook(target, detour); }
bool IsOldMono() { return Mono::IsOldMono; }
MonoString* GetCompanyName() { return Mono::mono_string_new(Mono::Domain, ((LemonLoader::CompanyName == NULL) ? "UNKNOWN" : LemonLoader::CompanyName)); }
MonoString* GetProductName() { return Mono::mono_string_new(Mono::Domain, ((LemonLoader::ProductName == NULL) ? "UNKNOWN" : LemonLoader::ProductName)); }
MonoString* GetAssemblyDirectory() { return Mono::mono_string_new(Mono::Domain, Mono::AssemblyPath); }
MonoString* GetMonoConfigDirectory() { return Mono::mono_string_new(Mono::Domain, Mono::ConfigPath); }
MonoString* GetExePath() { return Mono::mono_string_new(Mono::Domain, LemonLoader::ExePath); }
bool IsQuitFix() { return LemonLoader::QuitFix; }
bool IsDevModsOnly() { return LemonLoader::DevModsOnly; }
bool IsDevPluginsOnly() { return LemonLoader::DevPluginsOnly; }
bool AG_Force_Regenerate() { return LemonLoader::AG_Force_Regenerate; }
MonoString* AG_Force_Version_Unhollower() { if (LemonLoader::ForceUnhollowerVersion != NULL) return Mono::mono_string_new(Mono::Domain, LemonLoader::ForceUnhollowerVersion); return NULL; }
void SetTitleForConsole(MonoString* txt) { Console::SetTitle(Mono::mono_string_to_utf8(txt)); }

void Exports::AddInternalCalls()
{
	Mono::mono_add_internal_call("LemonLoader.Imports::UNLOAD_LemonLoader", LemonLoader::UNLOAD);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsIl2CppGame", IsIl2CppGame);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsDebugMode", IsDebugMode);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsConsoleEnabled", IsConsoleEnabled);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetGameDirectory", GetGameDirectory);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetGameDataDirectory", GetGameDataDirectory);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetAssemblyDirectory", GetAssemblyDirectory);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetMonoConfigDirectory", GetMonoConfigDirectory);
	Mono::mono_add_internal_call("LemonLoader.Imports::Hook", Hook);
	Mono::mono_add_internal_call("LemonLoader.Imports::Unhook", Unhook);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsOldMono", IsOldMono);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetCompanyName", GetCompanyName);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetProductName", GetProductName);
	Mono::mono_add_internal_call("LemonLoader.Imports::GetExePath", GetExePath);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsQuitFix", IsQuitFix);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsDevModsOnly", IsDevModsOnly);
	Mono::mono_add_internal_call("LemonLoader.Imports::IsDevPluginsOnly", IsDevPluginsOnly);
	Mono::mono_add_internal_call("LemonLoader.Imports::AG_Force_Regenerate", AG_Force_Regenerate);
	Mono::mono_add_internal_call("LemonLoader.Imports::AG_Force_Version_Unhollower", AG_Force_Version_Unhollower);

	Mono::mono_add_internal_call("LemonLoader.Console::Allocate", Console::Create);
	Mono::mono_add_internal_call("LemonLoader.Console::SetTitle", SetTitleForConsole);
	Mono::mono_add_internal_call("LemonLoader.Console::SetColor", Console::SetColor);

	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_Log", Log);
	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_LogColor", LogColor);
	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_LogWarning", LogWarning);
	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_LogError", LogError);
	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_LogDLLError", LogDLLError);
	Mono::mono_add_internal_call("LemonLoader.MelonModLogger::Native_LogDLLStatus", LogDLLStatus);
}