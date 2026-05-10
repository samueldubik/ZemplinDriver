// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePikoDriver_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PikoDriver;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PikoDriver()
	{
		if (!Z_Registration_Info_UPackage__Script_PikoDriver.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/PikoDriver",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x980B5F2A,
			0x25FF76CD,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PikoDriver.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_PikoDriver.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PikoDriver(Z_Construct_UPackage__Script_PikoDriver, TEXT("/Script/PikoDriver"), Z_Registration_Info_UPackage__Script_PikoDriver, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x980B5F2A, 0x25FF76CD));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
