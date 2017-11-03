#include "zadanie9.h"

std::ostream & comma(std::ostream & Out)
{
	Out << ", ";
	return Out;
}

std::ostream & colon(std::ostream & Out)
{
	Out << ": ";
	return Out;
}

std::istream & clearline(std::istream &In)
{
	while (In.peek() != EOF && In.get() != '\n');
	return In;
}

manip_ignore& manip_ignore::operator()(int _Size)
{
	Size = _Size;
	return *this;
}
manip_ignore ignore;

std::istream& operator >> (std::istream &In, const manip_ignore &Manip)
{
	In.ignore(Manip.Size, '\n');
	return In;
};


manip_index& manip_index::operator()(int _x, int _w)
{
	x = _x;
	w = _w;
	return *this;
}

manip_index index;

std::ostream& operator<<(std::ostream &Out, const manip_index &Manip)
{
	Out << '[';
	Out.width(Manip.w);
	Out << Manip.x << ']';
	return Out;
};



Line::Line()
{
	++s_Num;
	m_Num = s_Num;
	std::getline(std::cin, m_Line);
}


std::ostream& operator<<(std::ostream &Out, const Line &Obj)
{
	Out << '[' << Obj.m_Num << "]: " << Obj.m_Line << '\n';
	return Out;
}

