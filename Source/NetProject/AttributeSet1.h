// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSet1.generated.h"

/**
 * 
 */
UCLASS()
class NETPROJECT_API UAttributeSet1 : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Category = "Wizard Attributes | Health", EditAnywhere, BlueprintReadWrite)
		float Health;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	FGameplayAttribute HealthAttribute();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue);
};
