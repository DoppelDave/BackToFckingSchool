// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WwiseNiagara/Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNiagaraDataInterfaceWwiseEvent() {}

// Begin Cross Module References
AKAUDIO_API UClass* Z_Construct_UClass_UAkAudioEvent_NoRegister();
AKAUDIO_API UClass* Z_Construct_UClass_UAkRtpc_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraDataInterface();
UPackage* Z_Construct_UPackage__Script_WwiseNiagara();
WWISENIAGARA_API UClass* Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent();
WWISENIAGARA_API UClass* Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_NoRegister();
// End Cross Module References

// Begin Class UNiagaraDataInterfaceWwiseEvent
void UNiagaraDataInterfaceWwiseEvent::StaticRegisterNativesUNiagaraDataInterfaceWwiseEvent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNiagaraDataInterfaceWwiseEvent);
UClass* Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_NoRegister()
{
	return UNiagaraDataInterfaceWwiseEvent::StaticClass();
}
struct Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Category", "WwiseAudio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** This Data Interface can be used to post Wwise events driven by particle data. */" },
#endif
		{ "DisplayName", "Niagara Wwise Event" },
		{ "IncludePath", "Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This Data Interface can be used to post Wwise events driven by particle data." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventToPost_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The AkAudioEvent asset to post. */" },
#endif
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The AkAudioEvent asset to post." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameParameters_MetaData[] = {
		{ "Category", "Parameters" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A set of Game Parameters updated (via their index) in the Set Wwise Persistent Event Game Parameter module */" },
#endif
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A set of Game Parameters updated (via their index) in the Set Wwise Persistent Event Game Parameter module" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLimitPostsPerTick_MetaData[] = {
		{ "Category", "Audio" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPostsPerTick_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** This sets the max number of events posted on each tick.\n\x09 *  If more particles try to play a sound in a given tick, then it will play sounds until the limit is reached and discard the rest. */" },
#endif
		{ "EditCondition", "bLimitPostsPerTick" },
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This sets the max number of events posted on each tick.\nIf more particles try to play a sound in a given tick, then it will play sounds until the limit is reached and discard the rest." },
#endif
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopWhenComponentIsDestroyed_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If false then the event keeps playing after the Niagara component was destroyed (particle death, or system is stopped/destroyed).\n\x09Looping sounds are always stopped when the component is destroyed. */" },
#endif
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If false then the event keeps playing after the Niagara component was destroyed (particle death, or system is stopped/destroyed).\n      Looping sounds are always stopped when the component is destroyed." },
#endif
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOnlyActiveDuringGameplay_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, this data interface only processes sounds during active gameplay, and not while using Realtime Rendering in the open viewport.\n\x09 * This is useful when you are working in the preview window and the sounds annoy you. */" },
#endif
		{ "ModuleRelativePath", "Public/Wwise/Niagara/NiagaraDataInterfaceWwiseEvent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, this data interface only processes sounds during active gameplay, and not while using Realtime Rendering in the open viewport.\nThis is useful when you are working in the preview window and the sounds annoy you." },
#endif
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EventToPost;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameParameters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GameParameters;
	static void NewProp_bLimitPostsPerTick_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLimitPostsPerTick;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxPostsPerTick;
	static void NewProp_bStopWhenComponentIsDestroyed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopWhenComponentIsDestroyed;
#if WITH_EDITORONLY_DATA
	static void NewProp_bOnlyActiveDuringGameplay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnlyActiveDuringGameplay;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNiagaraDataInterfaceWwiseEvent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_EventToPost = { "EventToPost", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNiagaraDataInterfaceWwiseEvent, EventToPost), Z_Construct_UClass_UAkAudioEvent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventToPost_MetaData), NewProp_EventToPost_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_GameParameters_Inner = { "GameParameters", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAkRtpc_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_GameParameters = { "GameParameters", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNiagaraDataInterfaceWwiseEvent, GameParameters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameParameters_MetaData), NewProp_GameParameters_MetaData) };
void Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bLimitPostsPerTick_SetBit(void* Obj)
{
	((UNiagaraDataInterfaceWwiseEvent*)Obj)->bLimitPostsPerTick = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bLimitPostsPerTick = { "bLimitPostsPerTick", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNiagaraDataInterfaceWwiseEvent), &Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bLimitPostsPerTick_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLimitPostsPerTick_MetaData), NewProp_bLimitPostsPerTick_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_MaxPostsPerTick = { "MaxPostsPerTick", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNiagaraDataInterfaceWwiseEvent, MaxPostsPerTick), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPostsPerTick_MetaData), NewProp_MaxPostsPerTick_MetaData) };
void Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bStopWhenComponentIsDestroyed_SetBit(void* Obj)
{
	((UNiagaraDataInterfaceWwiseEvent*)Obj)->bStopWhenComponentIsDestroyed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bStopWhenComponentIsDestroyed = { "bStopWhenComponentIsDestroyed", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNiagaraDataInterfaceWwiseEvent), &Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bStopWhenComponentIsDestroyed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopWhenComponentIsDestroyed_MetaData), NewProp_bStopWhenComponentIsDestroyed_MetaData) };
#if WITH_EDITORONLY_DATA
void Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bOnlyActiveDuringGameplay_SetBit(void* Obj)
{
	((UNiagaraDataInterfaceWwiseEvent*)Obj)->bOnlyActiveDuringGameplay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bOnlyActiveDuringGameplay = { "bOnlyActiveDuringGameplay", nullptr, (EPropertyFlags)0x0010040800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNiagaraDataInterfaceWwiseEvent), &Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bOnlyActiveDuringGameplay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOnlyActiveDuringGameplay_MetaData), NewProp_bOnlyActiveDuringGameplay_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_EventToPost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_GameParameters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_GameParameters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bLimitPostsPerTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_MaxPostsPerTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bStopWhenComponentIsDestroyed,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::NewProp_bOnlyActiveDuringGameplay,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UNiagaraDataInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_WwiseNiagara,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::ClassParams = {
	&UNiagaraDataInterfaceWwiseEvent::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::Class_MetaDataParams), Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent()
{
	if (!Z_Registration_Info_UClass_UNiagaraDataInterfaceWwiseEvent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNiagaraDataInterfaceWwiseEvent.OuterSingleton, Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNiagaraDataInterfaceWwiseEvent.OuterSingleton;
}
template<> WWISENIAGARA_API UClass* StaticClass<UNiagaraDataInterfaceWwiseEvent>()
{
	return UNiagaraDataInterfaceWwiseEvent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNiagaraDataInterfaceWwiseEvent);
UNiagaraDataInterfaceWwiseEvent::~UNiagaraDataInterfaceWwiseEvent() {}
// End Class UNiagaraDataInterfaceWwiseEvent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Davis_Documents_Unreal_Projects_BackToFckingSchool_BTTFS_Plugins_WwiseNiagara_Source_WwiseNiagara_Public_Wwise_Niagara_NiagaraDataInterfaceWwiseEvent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNiagaraDataInterfaceWwiseEvent, UNiagaraDataInterfaceWwiseEvent::StaticClass, TEXT("UNiagaraDataInterfaceWwiseEvent"), &Z_Registration_Info_UClass_UNiagaraDataInterfaceWwiseEvent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNiagaraDataInterfaceWwiseEvent), 3763262581U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Davis_Documents_Unreal_Projects_BackToFckingSchool_BTTFS_Plugins_WwiseNiagara_Source_WwiseNiagara_Public_Wwise_Niagara_NiagaraDataInterfaceWwiseEvent_h_3687966540(TEXT("/Script/WwiseNiagara"),
	Z_CompiledInDeferFile_FID_Users_Davis_Documents_Unreal_Projects_BackToFckingSchool_BTTFS_Plugins_WwiseNiagara_Source_WwiseNiagara_Public_Wwise_Niagara_NiagaraDataInterfaceWwiseEvent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Davis_Documents_Unreal_Projects_BackToFckingSchool_BTTFS_Plugins_WwiseNiagara_Source_WwiseNiagara_Public_Wwise_Niagara_NiagaraDataInterfaceWwiseEvent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
