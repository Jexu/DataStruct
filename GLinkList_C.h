#pragma once
#include <iostream>
using namespace std;

namespace gll_c
{
	enum ElemTag {ATOM,LIST};

	template<typename T>
	/*���������ԭ��*/
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