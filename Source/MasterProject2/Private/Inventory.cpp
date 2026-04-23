#include "Inventory.h"

AInventory::AInventory()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AInventory::BeginPlay()
{
    Super::BeginPlay();

    // 아이템 도감 세팅
    ItemDatabase.Add(FName("Potion"),     FGameItemInfo(TEXT("회복 물약"), 100, NAME_None));
    ItemDatabase.Add(FName("Sword"),      FGameItemInfo(TEXT("전설의 검"), 1000, FName("Hero")));
    ItemDatabase.Add(FName("DragonScale"),FGameItemInfo(TEXT("용의 비늘"), 5000, FName("DragonSlayer")));
    
    // 테스트 실행
    AddItem(FName("Potion"));
    AddItem(FName("Sword"));
    AddItem(FName("DragonScale"));

    PrintBag();

    UseItem(FName("Potion"));  
    UseItem(FName("Sword"));    

    AcquireTitle(FName("Hero"));

    UseItem(FName("Sword"));      
    UseItem(FName("DragonScale"));  
}

void AInventory::AddItem(FName ItemKey)
{
    if (!ItemDatabase.Contains(ItemKey))
    {
        UE_LOG(LogTemp, Warning, TEXT("존재하지 않는 아이템: %s"), *ItemKey.ToString());
        return;
    }

    Bag.Add(ItemKey);
    UE_LOG(LogTemp, Log, TEXT("아이템 획득: %s"), *ItemKey.ToString());
}

void AInventory::UseItem(FName ItemKey)
{
    if (!Bag.Contains(ItemKey))
    {
        UE_LOG(LogTemp, Warning, TEXT("가방에 없음: %s"), *ItemKey.ToString());
        return;
    }

    // 도감에서 정보 가져오기
    FGameItemInfo* Info = ItemDatabase.Find(ItemKey);
    if (!Info) return;

    // 칭호 확인
    if (Info->RequiredTitle != NAME_None && !Titles.Contains(Info->RequiredTitle))
    {
        UE_LOG(LogTemp, Warning, TEXT("'%s' 칭호가 필요합니다!"), 
            *Info->RequiredTitle.ToString());
        return;
    }

    // 사용 성공
    Bag.RemoveSingle(ItemKey);
    UE_LOG(LogTemp, Log, TEXT("아이템 사용 성공: %s (가치 %d)"), 
        *Info->ItemName, Info->Value);
}

void AInventory::AcquireTitle(FName TitleName)
{
    Titles.Add(TitleName);   
    UE_LOG(LogTemp, Log, TEXT("칭호 획득: %s"), *TitleName.ToString());
}

void AInventory::PrintBag()
{
    UE_LOG(LogTemp, Log, TEXT("===== 가방 =====")); 
    for (const FName& Key : Bag)
    {
        if (FGameItemInfo* Info = ItemDatabase.Find(Key))
        {
            UE_LOG(LogTemp, Log, TEXT("- %s (가치 %d)"), *Info->ItemName, Info->Value);
        }
    }
}