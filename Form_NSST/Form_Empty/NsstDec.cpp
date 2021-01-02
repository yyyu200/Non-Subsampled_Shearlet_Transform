#pragma once
#include <math.h>
#include "NsstDec.h"
#include "MatlabFuncs.h"
#include "AtrousDec.h"
#include "ShearingFiltersMyer.h"

Cont* NsstDec1e(Matrix* image, struct ShearParameters shearParam, const char* lpfilt)
{
	int level = strlen((char*)shearParam.dcomp);
	
	//Laplacian Pyramid decomposition
	Cont* y = AtrousDec(image, lpfilt, level);

	Cont* dst = new Cont(level + 1);
	dst->mats[0] = y->mats[0];

	Cont* shearF = new Cont(level);

	Matrix* temp;
	for (int i = 0; i < level; i++)
	{
		temp = ShearingFiltersMyer(shearParam.dsize[i], shearParam.dcomp[i]);
		for (int j = 0; j < temp->GetSize(); j++)
			temp->mat[j] *= sqrt(shearParam.dsize[i]);
		shearF->mats[i] = temp;

		for (int k = 0; k < pow(2, shearParam.dcomp[i]); k++)
			dst->mats[i + 1] = Conv2(y->mats[i+1], shearF->mats[i][k], "same");
	}
	
	return dst;
}
