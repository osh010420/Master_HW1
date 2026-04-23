#pragma once

#include "CoreMinimal.h"
#include "GameItemInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString ItemName;

	UPROPERTY(EditAnywhere)
	int32 Value;

	UPROPERTY(EditAnywhere)
	FName RequiredTitle;

	FGameItemInfo()
		: ItemName(TEXT(""))
		, Value(0)
		, RequiredTitle(NAME_None)
	{
	}

	FGameItemInfo(const FString& InName, int32 InValue, FName InTitle)
		: ItemName(InName)
		, Value(InValue)
		, RequiredTitle(InTitle)
	{
	}
};