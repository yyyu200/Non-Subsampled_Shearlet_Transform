#pragma once
#include <stdlib.h> 
#include "MatlabFuncs.h"
#include <string.h>

// return g0, h0, g1, h1
Cont* AtrousFilters(const char* fname) {

	int h0Width = 7;
	int h0Height = 7;

	int h1Width = 10;
	int h1Height = 10;

	int g0Width = 10;
	int g0Height = 10;
	 
	int g1Width = 7;
	int g1Height = 7;

	if (!strcmp(fname, "maxflat")) {

		double h0[] = { -7.900496718847182e-07, 0., 0.000014220894093924927, 0.000025281589500310983, -0.000049773129328737247, -0.00022753430550279883, -0.00033182086219158167,
		   0,               0,              0,                   0,                       0,                          0,                     0,
		   0.000014220894093924927, 0., -0.0002559760936906487, -0.00045506861100559767,   0.0008959163279172705,   0.004095617499050379,    0.00597277551944847,
		   0.000025281589500310983, 0., -0.00045506861100559767, 0.0009765625             ,0.0015927401385195919, -0.0087890625, -0.01795090623402861,
		  -0.000049773129328737247, 0.,  0.0008959163279172705,  0.0015927401385195919, -0.0031357071477104465, -0.014334661246676327, -0.020904714318069645,
		  -0.00022753430550279883,  0.,  0.004095617499050379 ,-0.0087890625, -0.014334661246676327,    0.0791015625      ,      0.16155815610625748,
		  -0.00033182086219158167,  0.,  0.00597277551944847, -0.01795090623402861, -0.020904714318069645,    0.16155815610625748,     0.3177420190660832 };

		double g0[] = { -6.391587676622346e-010,             0.,                1.7257286726880333e-08,    3.067962084778726e-08, -1.3805829381504267e-07, -5.522331752601707e-07,
			-3.3747582932565985e-07,    1.9328161134105974e-06,     5.6949046198705095e-06,    7.649452131381623e-06,
			0.0,                          0.,                      0.,                          0.,               0.,  0.,  0.,  0.,  0.,  0.,
			 1.7257286726880333e-08,             0., -4.65946741625769e-07, -8.283497628902559e-07,    3.727573933006152e-06,    0.000014910295732024608,
			 9.111847391792816e-06, -0.000052186035062086126, -0.00015376242473650378, -0.00020653520754730382,
			 3.067962084778726e-08,              0., -8.283497628902559e-07, -1.2809236054493144e-06,   6.6267981031220475e-06,   0.00002305662489808766,
			 0.000010064497559808503, -0.0000806981871433068, -0.00021814634152337594, -0.00028666046030363884,
			-1.3805829381504267e-07,             0.,                3.727573933006152e-06,     6.6267981031220475e-06, -0.000029820591464049215, -0.00011928236585619686, 
			- 0.00007289477913434253,    0.000417488280496689,       0.0012300993978920302,     0.0016522816603784306,
			-5.522331752601707e-07,              0. ,               0.000014910295732024608 ,  0.00002305662489808766 ,- 0.00011928236585619686, - 0.00041501924816557786, 
			- 0.00018116095607655303,    0.0014525673685795225 ,     0.0039266341474207675 ,    0.005159888285465499,
			-3.3747582932565985e-07 ,            0. ,               9.111847391792816e-06,     0.000010064497559808503 ,- 0.00007289477913434253, - 0.00018116095607655303,
			 0.001468581806076247,     0.0006340633462679356, - 0.01181401175635013, - 0.021745034491193898,
			 1.9328161134105974e-06,             0., - 0.000052186035062086126, - 0.0000806981871433068,    0.000417488280496689,    0.0014525673685795225,
			 0.0006340633462679356, - 0.005083985790028328, - 0.013743219515972684, - 0.018059608999129246,
			 5.6949046198705095e-06,             0., - 0.00015376242473650378, - 0.00021814634152337594,   0.0012300993978920302,   0.0039266341474207675 ,
			- 0.01181401175635013, - 0.013743219515972684 ,      0.0826466923977296  ,      0.1638988884584603,
			 7.649452131381623e-06 ,             0., - 0.00020653520754730382, - 0.00028666046030363884,   0.0016522816603784306,   0.005159888285465499 ,
			- 0.021745034491193898 ,- 0.018059608999129246  ,     0.1638988884584603 ,       0.31358726209239235 };

		double g1[] = { -7.900496718847182e-07,    0.,      0.000014220894093924927, 0.000025281589500310983, - 0.000049773129328737247, - 0.00022753430550279883, - 0.00033182086219158167,
				0,                 0   ,             0      ,          0        ,                    0      ,                 0        ,               0,
			0.000014220894093924927,  0., - 0.0002559760936906487, - 0.00045506861100559767,   0.0008959163279172705,    0.004095617499050379 ,   0.00597277551944847,
			0.000025281589500310983,  0., - 0.00045506861100559767, - 0.0009765625 ,            0.0015927401385195919  ,  0.0087890625    ,        0.01329909376597139,
			-0.000049773129328737247,  0.,      0.0008959163279172705 ,  0.0015927401385195919, - 0.0031357071477104465, - 0.014334661246676327, - 0.020904714318069645,
			-0.00022753430550279883,   0.,     0.004095617499050379,    0.0087890625, - 0.014334661246676327, - 0.0791015625, - 0.1196918438937425,
			-0.00033182086219158167,   0.,      0.00597277551944847,     0.01329909376597139, - 0.020904714318069645, - 0.1196918438937425,      0.8177420190660831 };

		double h1[] = { 6.391587676622346e-010,       0.0, -1.7257286726880333e-08 ,-3.067962084778726e-08     ,1.3805829381504267e-07  ,5.522331752601707e-07 ,
			3.3747582932565985e-07, -1.9328161134105974e-06 ,-5.6949046198705095e-06, -7.649452131381623e-06,
			0.0,                     0.0,                           0.0,                            0.0,                      0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
			-1.7257286726880333e-08       ,0.0,                  4.65946741625769e-07             ,8.283497628902559e-07 ,-3.727573933006152e-06 ,-0.000014910295732024608,
			-9.111847391792816e-06,   0.000052186035062086126  ,0.00015376242473650378           ,0.00020653520754730382,
			-3.067962084778726e-08        ,0.0,                  8.283497628902559e-07 ,-2.9917573832012203e-07 ,-6.6267981031220475e-06   ,5.3851632897621965e-06 ,
			0.00004049868144081346 ,-0.00001884807151416769 ,-0.00023692226948222173 ,-0.0003769812640795245,
			1.3805829381504267e-07       ,0.0, -3.727573933006152e-06 ,-6.6267981031220475e-06    ,0.000029820591464049215  ,0.00011928236585619686 ,
			0.00007289477913434253 ,-0.000417488280496689 ,-0.0012300993978920302 ,-0.0016522816603784306,
			5.522331752601707e-07        ,0.0, -0.000014910295732024608          ,5.3851632897621965e-06    ,0.00011928236585619686 ,-0.00009693293921571956 ,
			-0.0007289762659346422   ,0.00033926528725501844   ,0.004264600850679991             ,0.006785662753431441,
			3.3747582932565985e-07       ,0.0, -9.111847391792816e-06            ,0.00004049868144081346    ,0.00007289477913434253 ,-0.0007289762659346422 ,
			-0.001468581806076247    ,0.002551416930771248     ,0.01181401175635013              ,0.017093222023136675,
			-1.9328161134105974e-06       ,0.0,                  0.000052186035062086126 ,-0.00001884807151416769 ,-0.000417488280496689     ,0.00033926528725501844 ,
			0.002551416930771248 ,-0.0011874285053925643 ,-0.01492610297737997 ,-0.023749819637010044,
			-5.6949046198705095e-06       ,0.0,                  0.00015376242473650378 ,-0.00023692226948222173 ,-0.0012300993978920302    ,0.004264600850679991 ,
			0.01181401175635013 ,-0.01492610297737997 ,-0.0826466923977296 ,-0.12203257624594532,
			-7.649452131381623e-06        ,0.0,                  0.00020653520754730382 ,-0.0003769812640795245 ,-0.0016522816603784306    ,0.006785662753431441 ,
			0.017093222023136675 ,-0.023749819637010044 ,-0.12203257624594532               ,0.821896776039774 };


		/*
			g0 = [g0   fliplr(g0(:, 1 : end - 1))];
			g0 = [g0; flipud(g0(1:end - 1, : ))];
			h0 = [h0   fliplr(h0(:, 1 : end - 1))];
			h0 = [h0; flipud(h0(1:end - 1, : ))];
		
			g1 = [g1   fliplr(g1(:, 1 : end - 1))];
			g1 = [g1; flipud(g1(1:end - 1, : ))];
			h1 = [h1   fliplr(h1(:, 1 : end - 1))];
			h1 = [h1; flipud(h1(1:end - 1, : ))];
		*/

		// g0
		Matrix* cutG0 = MatrixCut(g0, g0Height, g0Width, 0, g0Height - 1, 0, g0Width - 2);
		Matrix* extG0 = MatrixColExtend(g0, g0Height, g0Width, Fliplr(cutG0->mat, cutG0->height, cutG0->width), cutG0->height, cutG0->width);
		// g0
		Matrix* cutExtG0 = MatrixCut(extG0->mat, extG0->height, extG0->width, 0, extG0->height - 2, 0, extG0->width - 1);
		Matrix* retG0 = MatrixRowExtend(extG0->mat, extG0->height, extG0->width, Flipud(cutExtG0->mat, cutExtG0->height, cutExtG0->width), cutExtG0->height, cutExtG0->width);
		// h0
		Matrix* cutH0 = MatrixCut(h0, h0Height, h0Width, 0, h0Height - 1, 0, h0Width - 2);
		Matrix* extH0 = MatrixColExtend(h0, h0Height, h0Width, Fliplr(cutH0->mat, cutH0->height, cutH0->width), cutH0->height, cutH0->width);
		// h0
		Matrix* cutExtH0 = MatrixCut(extH0->mat, extH0->height, extH0->width, 0, extH0->height - 2, 0, extH0->width - 1);
		Matrix* retH0 = MatrixRowExtend(extH0->mat, extH0->height, extH0->width, Flipud(cutExtH0->mat, cutExtH0->height, cutExtH0->width), cutExtH0->height, cutExtH0->width);
		
		// g1
		Matrix* cutG1 = MatrixCut(g1, g1Height, g1Width, 0, g1Height - 1, 0, g1Width - 2);
		Matrix* extG1 = MatrixColExtend(g1, g1Height, g1Width, Fliplr(cutG1->mat, cutG1->height, cutG1->width), cutG1->height, cutG1->width);
		// g1
		Matrix* cutExtG1 = MatrixCut(extG1->mat, extG1->height, extG1->width, 0, extG1->height - 2, 0, extG1->width - 1);
		Matrix* retG1 = MatrixRowExtend(extG1->mat, extG1->height, extG1->width, Flipud(cutExtG1->mat, cutExtG1->height, cutExtG1->width), cutExtG1->height, cutExtG1->width);
		// h1
		Matrix* cutH1 = MatrixCut(h1, h1Height, h1Width, 0, h1Height - 1, 0, h1Width - 2);
		Matrix* extH1 = MatrixColExtend(h1, h1Height, h1Width, Fliplr(cutH1->mat, cutH1->height, cutH1->width), cutH1->height, cutH1->width);
		// h1
		Matrix* cutExtH1 = MatrixCut(extH1->mat, extH1->height, extH1->width, 0, extH1->height - 2, 0, extH1->width - 1);
		Matrix* retH1 = MatrixRowExtend(extH1->mat, extH1->height, extH1->width, Flipud(cutExtH1->mat, cutExtH1->height, cutExtH1->width), cutExtH1->height, cutExtH1->width);
	
		Cont* ret = new Cont(4);
		ret->mats[0] = retG0;
		ret->mats[1] = retH0;
		ret->mats[2] = retG1;
		ret->mats[3] = retH1;

		return ret;
	}

}






