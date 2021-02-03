#include "func.h"

//void sortTrain(train arr[], const int LENGTH) {
//	for (int i = 0; i < LENGTH - 1; i++)
//		for (int j = i + 1; j < LENGTH; j++) {
//			if (strcmp(arr[i].getCity().c_str(), arr[j].getCity().c_str()) > 0) swap(arr[i], arr[j]);
//			if (arr[i].getCity() == arr[j].getCity())
//				if (strcmp(arr[i].getTime().c_str(), arr[j].getTime().c_str()) > 0) swap(arr[i], arr[j]);
//		}
//}

void sortTrain(train arr[], const int LENGTH) {
	for (int i = 0; i < LENGTH - 1; i++)
		for (int j = i + 1; j < LENGTH; j++) {
			if (arr[i].getCity()> arr[j].getCity()) swap(arr[i], arr[j]);
			if (arr[i].getCity() == arr[j].getCity())
				if (arr[i].getTime() > arr[j].getTime()) swap(arr[i], arr[j]);
		}
}

void getTrainInfo(train arr[], int nomer, const int LENGTH) {


	for (int i = 0; i < LENGTH; i++)
	{
		if (arr[i].getNumber() == nomer)
		{
			arr[i].getInfo();
			break;
		}
		else if (i == (LENGTH - 1) && arr[i].getNumber() != nomer) {
			cout << "Не найдено поезда с таким номером" << endl;
			break;
		}
	}

}