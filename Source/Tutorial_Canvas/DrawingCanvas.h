// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "Engine/Texture2D.h"
#include "Object.h"
#include "DrawingCanvas.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TUTORIAL_CANVAS_API UDrawingCanvas : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		UTexture2D* dynamicCanvas;

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void InitializeCanvas(const int32 pixelsH, const int32 pixelsV);
	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void UpdateCanvas();
	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void ClearCanvas();

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void InitializeDrawingTools(const int32 brushRadius);
	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void DrawDot(const int32 pixelCoordX, const int32 pixelCoordY);

	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void InitializeDecal(const UTexture2D* decalTexture);
	UFUNCTION(BlueprintCallable, Category = DrawingTools)
		void DrawDecal(const int32 pixelCoordX, const int32 pixelCoordY);

	UDrawingCanvas();
	~UDrawingCanvas();

private:

	// canvas
	std::unique_ptr<uint8[]> canvasPixelData;
	int canvasWidth;
	int canvasHeight;
	int bytesPerPixel;
	int bufferPitch;
	int bufferSize;

	// draw brush tool
	std::unique_ptr<uint8[]> canvasBrushMask;
	int radius;
	int brushBufferSize;

	// decal tool
	std::unique_ptr<uint8[]> canvasDecalImage;
	int decalWidth;
	int decalHeight;
	int decalBufferSize;

	std::unique_ptr<FUpdateTextureRegion2D> echoUpdateTextureRegion;
	void setPixelColor(uint8*& pointer, uint8 red, uint8 green, uint8 blue, uint8 alpha);
};
