// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CarPawn.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCarPawn() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
PIKODRIVER_API UClass* Z_Construct_UClass_ACarPawn();
PIKODRIVER_API UClass* Z_Construct_UClass_ACarPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_PikoDriver();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACarPawn *****************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACarPawn;
UClass* ACarPawn::GetPrivateStaticClass()
{
	using TClass = ACarPawn;
	if (!Z_Registration_Info_UClass_ACarPawn.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CarPawn"),
			Z_Registration_Info_UClass_ACarPawn.InnerSingleton,
			StaticRegisterNativesACarPawn,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ACarPawn.InnerSingleton;
}
UClass* Z_Construct_UClass_ACarPawn_NoRegister()
{
	return ACarPawn::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACarPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is an unreal engine class\n" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CarPawn.h" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is an unreal engine class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAcces", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicsBody_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CarMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseLookSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinCameraPitch_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCameraPitch_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccelerationForce_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringTorque_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinearDamping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AngularDamping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CarMassKg_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LateralGrip_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringEfficiencyCurve_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Steering" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxForwardSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Steering" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringInputInterpSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Steering" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReverseAccelerationForce_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrakeForce_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoastingDragForce_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxReverseSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccelerationFalloffExponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinAccelerationFactor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Driving|Acceleration" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseKeyboardFallback_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/CarPawn.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ACarPawn constinit property declarations *********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsBody;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CarMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseLookSensitivity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinCameraPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCameraPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AccelerationForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringTorque;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LinearDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngularDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CarMassKg;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LateralGrip;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SteeringEfficiencyCurve;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxForwardSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringInputInterpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReverseAccelerationForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CoastingDragForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxReverseSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AccelerationFalloffExponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAccelerationFactor;
	static void NewProp_bUseKeyboardFallback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseKeyboardFallback;
	static void NewProp_bShowDebugInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugInput;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ACarPawn constinit property declarations ***********************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACarPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACarPawn_Statics

// ********** Begin Class ACarPawn Property Definitions ********************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_PhysicsBody = { "PhysicsBody", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, PhysicsBody), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicsBody_MetaData), NewProp_PhysicsBody_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_CarMesh = { "CarMesh", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, CarMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CarMesh_MetaData), NewProp_CarMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_ThrottleInput = { "ThrottleInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, ThrottleInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrottleInput_MetaData), NewProp_ThrottleInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringInput = { "SteeringInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, SteeringInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringInput_MetaData), NewProp_SteeringInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MouseLookSensitivity = { "MouseLookSensitivity", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MouseLookSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseLookSensitivity_MetaData), NewProp_MouseLookSensitivity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MinCameraPitch = { "MinCameraPitch", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MinCameraPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinCameraPitch_MetaData), NewProp_MinCameraPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxCameraPitch = { "MaxCameraPitch", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MaxCameraPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCameraPitch_MetaData), NewProp_MaxCameraPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_AccelerationForce = { "AccelerationForce", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, AccelerationForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccelerationForce_MetaData), NewProp_AccelerationForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringTorque = { "SteeringTorque", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, SteeringTorque), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringTorque_MetaData), NewProp_SteeringTorque_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_LinearDamping = { "LinearDamping", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, LinearDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinearDamping_MetaData), NewProp_LinearDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_AngularDamping = { "AngularDamping", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, AngularDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AngularDamping_MetaData), NewProp_AngularDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_CarMassKg = { "CarMassKg", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, CarMassKg), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CarMassKg_MetaData), NewProp_CarMassKg_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_LateralGrip = { "LateralGrip", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, LateralGrip), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LateralGrip_MetaData), NewProp_LateralGrip_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringEfficiencyCurve = { "SteeringEfficiencyCurve", nullptr, (EPropertyFlags)0x0144000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, SteeringEfficiencyCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringEfficiencyCurve_MetaData), NewProp_SteeringEfficiencyCurve_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxForwardSpeed = { "MaxForwardSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MaxForwardSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxForwardSpeed_MetaData), NewProp_MaxForwardSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringInputInterpSpeed = { "SteeringInputInterpSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, SteeringInputInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringInputInterpSpeed_MetaData), NewProp_SteeringInputInterpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_ReverseAccelerationForce = { "ReverseAccelerationForce", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, ReverseAccelerationForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReverseAccelerationForce_MetaData), NewProp_ReverseAccelerationForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_BrakeForce = { "BrakeForce", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, BrakeForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrakeForce_MetaData), NewProp_BrakeForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_CoastingDragForce = { "CoastingDragForce", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, CoastingDragForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoastingDragForce_MetaData), NewProp_CoastingDragForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxReverseSpeed = { "MaxReverseSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MaxReverseSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxReverseSpeed_MetaData), NewProp_MaxReverseSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_AccelerationFalloffExponent = { "AccelerationFalloffExponent", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, AccelerationFalloffExponent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccelerationFalloffExponent_MetaData), NewProp_AccelerationFalloffExponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_MinAccelerationFactor = { "MinAccelerationFactor", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACarPawn, MinAccelerationFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinAccelerationFactor_MetaData), NewProp_MinAccelerationFactor_MetaData) };
void Z_Construct_UClass_ACarPawn_Statics::NewProp_bUseKeyboardFallback_SetBit(void* Obj)
{
	((ACarPawn*)Obj)->bUseKeyboardFallback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_bUseKeyboardFallback = { "bUseKeyboardFallback", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACarPawn), &Z_Construct_UClass_ACarPawn_Statics::NewProp_bUseKeyboardFallback_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseKeyboardFallback_MetaData), NewProp_bUseKeyboardFallback_MetaData) };
void Z_Construct_UClass_ACarPawn_Statics::NewProp_bShowDebugInput_SetBit(void* Obj)
{
	((ACarPawn*)Obj)->bShowDebugInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACarPawn_Statics::NewProp_bShowDebugInput = { "bShowDebugInput", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACarPawn), &Z_Construct_UClass_ACarPawn_Statics::NewProp_bShowDebugInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugInput_MetaData), NewProp_bShowDebugInput_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACarPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_PhysicsBody,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_CarMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_InputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_ThrottleInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MouseLookSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MinCameraPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxCameraPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_AccelerationForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringTorque,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_LinearDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_AngularDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_CarMassKg,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_LateralGrip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringEfficiencyCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxForwardSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_SteeringInputInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_ReverseAccelerationForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_BrakeForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_CoastingDragForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MaxReverseSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_AccelerationFalloffExponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_MinAccelerationFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_bUseKeyboardFallback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarPawn_Statics::NewProp_bShowDebugInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACarPawn_Statics::PropPointers) < 2048);
// ********** End Class ACarPawn Property Definitions **********************************************
UObject* (*const Z_Construct_UClass_ACarPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_PikoDriver,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACarPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACarPawn_Statics::ClassParams = {
	&ACarPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACarPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACarPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACarPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ACarPawn_Statics::Class_MetaDataParams)
};
void ACarPawn::StaticRegisterNativesACarPawn()
{
}
UClass* Z_Construct_UClass_ACarPawn()
{
	if (!Z_Registration_Info_UClass_ACarPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACarPawn.OuterSingleton, Z_Construct_UClass_ACarPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACarPawn.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACarPawn);
ACarPawn::~ACarPawn() {}
// ********** End Class ACarPawn *******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h__Script_PikoDriver_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACarPawn, ACarPawn::StaticClass, TEXT("ACarPawn"), &Z_Registration_Info_UClass_ACarPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACarPawn), 1548768540U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h__Script_PikoDriver_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h__Script_PikoDriver_3239895841{
	TEXT("/Script/PikoDriver"),
	Z_CompiledInDeferFile_FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h__Script_PikoDriver_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_samue_Documents_Unreal_Projects_PikoDriver_Source_PikoDriver_Public_CarPawn_h__Script_PikoDriver_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
