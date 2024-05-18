#include <iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
using namespace std;

void insertionSort(int numbers[10], int size)
{
    int temp =0;
    int leftIndex;
    for(int i = 1; i<size; i++)
    {
        temp = numbers[i];
        leftIndex = i-1;

        while(leftIndex >= 0 && numbers[leftIndex] > temp)
        {
            numbers[leftIndex+1] = numbers[leftIndex];
            leftIndex--;
        }
        numbers[leftIndex+1] = temp;
    }
        for(int i = 0; i<10; i++)
    {
        cout << numbers[i] << ' ';
    }
}
class Phyllotaxis : public olc::PixelGameEngine {
public:
    Phyllotaxis() {
        sAppName = "Spirals are goated (with the sauce)";
    }

private:
    int n = 0;
    int c = 22.0;

public:
    bool OnUserCreate() override {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        float a = n * dtor(137.5f);
        float r = c * sqrtf(n);

        float x = r * cosf(a) + ScreenWidth() / 2;
        float y = r * sinf(a) + ScreenHeight() / 2;
        int temp = a;
        olc::Pixel color = HSVtoRGB((temp-n*2 % 256) / 255.0f, 1.0f, 1.0f);
        FillCircle(x, y, 4, color);

        n++;

        return true;
    }
};

int main()
{

	Phyllotaxis demo;
	if (demo.Construct(800, 800, 1, 1, false, true))
		demo.Start();
	return 0;
        int nums[10] = {10,5,3,17,23,2,5,9,91,14}; 
    for(int i = 0; i<10; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    insertionSort(nums,10);
    
}
