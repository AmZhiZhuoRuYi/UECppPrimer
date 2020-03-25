// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"

void UMyObject::MyFunction()
{
	UE_LOG(LogTemp, Log, TEXT("Hello world"));
	UE_LOG(LogTemp, Warning, TEXT("Hello world"));
	UE_LOG(LogTemp, Error, TEXT("Hello world"));
}
