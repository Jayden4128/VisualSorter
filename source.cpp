#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int ARR_LENGTH = 200;
void insertionSort(int numbers[10], int size)
{
	int temp = 0;
	int leftIndex;
	for (int i = 1; i < size; i++)
	{
		temp = numbers[i];
		leftIndex = i - 1;

		while (leftIndex >= 0 && numbers[leftIndex] > temp)
		{
			numbers[leftIndex + 1] = numbers[leftIndex];
			leftIndex--;
		}
		numbers[leftIndex + 1] = temp;
	}
	/*for (int i = 0; i < 10; i++)
	{
		std::cout << numbers[i] << ' ';
	}
	*/
}
// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
	public:
	Example()
	{
		// Name your application
		sAppName = "NotExample";
	}
	private: 
	int arr[ARR_LENGTH] = { 0 };
	int i = 0;
	public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		for (int i = 0; i < ARR_LENGTH; i++)
		{
			arr[i] = i + 1;
		}
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (i < ARR_LENGTH)
		{
			int temp = arr[i];
			int leftIndex = i - 1;
			while (leftIndex >= 0 && arr[leftIndex] > temp)
			{
				arr[leftIndex + 1] = arr[leftIndex];
				leftIndex--;
			}
			arr[leftIndex + 1] = temp;
			i++;
		}
		Clear(olc::Pixel(0, 0, 0));
		int size = ScreenWidth() / ARR_LENGTH;
		if (GetMouse(olc::Mouse::LEFT).bReleased)
		{
			shuffle();
			i = 0;
		}

		for (int i = 0; i < ARR_LENGTH; i++)
		{
			//DrawCircle(i * size, ScreenHeight() - arr[i] * size, size, olc::Pixel(255, 255, 255));
			FillRect(i*size, ScreenHeight() - arr[i]*size, size, arr[i]*size,olc::Pixel(35,70,220));
		}
		
		return true;
	}
	void shuffle()
	{
		for (int i = 0; i < ARR_LENGTH; i++)
		{
			int j = rand() % ARR_LENGTH;
			std::swap(arr[i], arr[j]);
		}
	}
};

int main()
{

	Example demo;
	if (demo.Construct(200, 200, 4, 4, false, true))
		demo.Start();
	return 0;
	/*int nums[10] = {10,5,3,17,23,2,5,9,91,14};
	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << ' ';
	}
	std::cout << endl;
	insertionSort(nums, 10);
	*/
}