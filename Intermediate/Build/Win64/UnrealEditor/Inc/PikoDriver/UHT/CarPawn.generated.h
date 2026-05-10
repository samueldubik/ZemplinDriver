// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CarPawn.h"

#ifdef PIKODRIVER_CarPawn_generated_h
#error "CarPawn.generated.h already included, missing '#pragma once' in CarPawn.h"
#endif
#define PIKODRIVER_CarPawn_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACarPawn *****************************************************************
struct Z_Construct_UClass_ACarPawn_Statics;
PIKODRIVER_API UClass* Z_Construct_UClass_ACarPawn_NoRegister();

#define FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACarPawn(); \
	friend struct ::Z_Construct_UClass_ACarPawn_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PIKODRIVER_API UClass* ::Z_Construct_UClass_ACarPawn_NoRegister(); \
public: \
	DECLARE_CLASS2(ACarPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PikoDriver"), Z_Construct_UClass_ACarPawn_NoRegister) \
	DECLARE_SERIALIZER(ACarPawn)


#define FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_42_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACarPawn(ACarPawn&&) = delete; \
	ACarPawn(const ACarPawn&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACarPawn) \
	NO_API virtual ~ACarPawn();


#define FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_36_PROLOG
#define FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_42_INCLASS_NO_PURE_DECLS \
	FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACarPawn;

// ********** End Class ACarPawn *******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
