// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet1.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"

void UAttributeSet1::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("This AS is ready to be changed"));

    UAbilitySystemComponent* Source = Data.EffectSpec.GetContext().GetOriginalInstigatorAbilitySystemComponent();
    if (HealthAttribute() == Data.EvaluatedData.Attribute)
    {
        AActor* DamagedActor = nullptr;
        AController* DamagedController = nullptr;
        if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
        {
            DamagedActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
            DamagedController = Data.Target.AbilityActorInfo->PlayerController.Get();

            UE_LOG(LogTemp, Warning, TEXT("The DamagedActor Name is:%s"), *(DamagedActor->GetName()));

        }
    }
    return;
}

FGameplayAttribute UAttributeSet1::HealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSet1::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSet1, Health));
	return FGameplayAttribute(Property);
}

//在属性修改之前进行的操作，此处检测生命值不超过100
void UAttributeSet1::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("PreAttributeChange AttributeSet1"));

	if (Attribute == HealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, 100.f);

		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("AttributeSet1 29"));
	}
}