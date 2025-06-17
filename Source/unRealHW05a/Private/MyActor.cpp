// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include <iostream>

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//���� �Լ�
int AMyActor::Rand() {
    int random = FMath::RandRange(0, 1);
    return random;
}

//�Ÿ��� ���ϴ� �޼���
double AMyActor::Distance(double x, double y)
{
    double distance = FMath::Sqrt(x + y);
    return distance;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    FVector CurrentLocation = GetActorLocation();
    double xd = 0.0;
    double yd = 0.0;
    int eventNum = 0;
    //10�� �̵��ϱ�
    for (int32 i = 0; i < 10; ++i) {
        double x = 0.0;
        double y = 0.0;
        if (Rand() == 1) {  //X ��ǥ
            CurrentLocation.X += 1.0f;  // X ��+1
            x = 1.0;
            xd += 1.0;
        }
        if (Rand() == 1) { // Y ��+1
            CurrentLocation.Y += 1.0f;
            y = 1.0;
            yd += 1.0;
        }
        SetActorLocation(CurrentLocation);  //�̵�
        if (Rand() == 1) { // 50%Ȯ��
            UE_LOG(LogTemp, Warning, TEXT("Big EVENT (50%%)"));    //�α� ���
            ++eventNum;
        }
        UE_LOG(LogTemp, Warning, TEXT("MOVE DISTANCE : %f"), Distance(x, y));
        UE_LOG(LogTemp, Warning, TEXT("MOVE to ( %f, %f )"), xd, yd);    //�α� ���
    }
    UE_LOG(LogTemp, Warning, TEXT("TOTAL MOVE IS : %f"), Distance(xd, yd));
    UE_LOG(LogTemp, Warning, TEXT("TOTAL EVENT IS : %d"), eventNum);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

