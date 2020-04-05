#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	const int TOPE = 100;
	float v1 [TOPE] = {2,3,8,22,44,88,99,100,101,255,665};
	float v2 [TOPE] = {1,3,4,5,6,25,87,89,99,100,500,1000};
	float res [2*TOPE];

	int tam_v1=11, tam_v2=12; // 0 <= tam_v1, tam_v2 < TOPE
	int tam_res = tam_v1+tam_v2; // 0 <= tam_res < 2*TOPE

	float *ptrV1 = v1;
	float *ptrV2 = v2;
	float *ptrRES = res;

	const float *v1_fin = v1+tam_v1;
	const float *v2_fin = v2+tam_v2;

	while(ptrV1 < (v1_fin) || ptrV2 < (v2_fin)){
		if(ptrV1 < (v1_fin) && ptrV2 < (v2_fin)){
			if(*(ptrV1) < *(ptrV2)){
				*(ptrRES) = *(ptrV1);
				ptrV1++;
			}
			else{
				*(ptrRES) = *(ptrV2);
				ptrV2++;
			}
		}
		else if(ptrV1 < (v1_fin)){
			*(ptrRES) = *(ptrV1);
			ptrV1++;
		}
		else{
			*(ptrRES) = *(ptrV2);
			ptrV2++;
		}
		ptrRES++;
	}

	for(int i=0; i<tam_res; i++){
		cout << *(res+i) << endl;
	}

	system ("pause");

}