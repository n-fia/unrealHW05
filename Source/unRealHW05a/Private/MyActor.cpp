// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include <iostream>



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


//랜덤 함수
int AMyActor::Rand() {
    int random = FMath::RandRange(0, 1);
    return random;
}

//거리를 구하는 메서드
double AMyActor::Distance(double x, double y)
{
    double distance = FMath::Sqrt(x + y);
    return distance;
}

void AMyActor::move() {
    
    //10번 이동하기
    FVector CurrentLocation = GetActorLocation();

    double x = 0.0;
    double y = 0.0;
    if (Rand() == 1) {  //X 좌표
        CurrentLocation.X += 1.0f;  // X 값+1
        x = 1.0;
        xd += 1.0;
    }
    if (Rand() == 1) { // Y 값+1
        CurrentLocation.Y += 1.0f;
        y = 1.0;
        yd += 1.0;
    }
    SetActorLocation(CurrentLocation);  //이동
    if (Rand() == 1) { // 50%확률
        UE_LOG(LogTemp, Warning, TEXT("Big EVENT (50%%)"));    //로그 출력
        ++eventNum;
    }
    UE_LOG(LogTemp, Warning, TEXT("MOVE DISTANCE : %f"), Distance(x, y));
    UE_LOG(LogTemp, Warning, TEXT("MOVE to ( %f, %f )"), xd, yd);    //로그 출력

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    timeSum += DeltaTime;

    if (maxNum<=10 && timeSum >= timeMove) { //2초마다
        move();
        timeSum = 0.0f;
        ++maxNum;
        if (maxNum >= 11) {
            UE_LOG(LogTemp, Warning, TEXT("TOTAL MOVE IS : %f"), Distance(xd, yd));
            UE_LOG(LogTemp, Warning, TEXT("TOTAL EVENT IS : %d"), eventNum);

        }
    }
}

