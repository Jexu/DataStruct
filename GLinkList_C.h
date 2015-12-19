#pragma once
#include <iostream>
using namespace std;

namespace gll_c
{
	enum ElemTag {ATOM,LIST};

	template<typename T>
	/*广义表数据原型*/
	struct GLINKLIST
	{
		ElemTag tag;
		union
		{
			T atom;
			struct
			{
				GLINKLIST *headP;
				GLINKLIST *tailP;
			};
		};
	};
}