#include "zadanie9.h"
int Line::s_Num = 0;
int main()
{
	std::vector<Line> Vec;

	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());
	Vec.push_back(Line());


	std::sort(Vec.begin(), Vec.end(), [](const Line& A, const Line& B) { return A.m_Line<B.m_Line; });

	for (auto &i : Vec)
	{
		std::cout << i;
	}

	std::cout << "index (25,5)" << std::endl;
	std::cout << index(25, 5) << std::endl;
}