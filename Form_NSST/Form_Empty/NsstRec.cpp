#include "NsstRec.h"
#include "MatlabFuncs.h"
#include "AtrousRec.h"

Matrix* NsstRec1(Cont* dst, const char* lpfilt) {

	int level = dst->matNums - 1;
	
	Cont* y = new Cont(level + 1);

	y->mats[0] = dst->mats[0];


	for (int i = 1; i <= level; i++) {
		
		y->mats[i] = Sum(dst->mats[i], 3);
	}
	
	return AtrousRec(y, lpfilt);
}