// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameItemInfo.h"
#include "Inventory.generated.h"

UCLASS()
class MASTERPROJECT2_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 1. 가방 (TArray)
	TArray<FName> Bag;

	// 2. 아이템 도감 (TMap)
	TMap<FName, FGameItemInfo> ItemDatabase;

	// 3. 획득한 칭호 (TSet)
	TSet<FName> Titles;
public:	
	void AddItem(FName ItemKey);
	void UseItem(FName ItemKey);
	void AcquireTitle(FName TitleName);
	void PrintBag();

};
