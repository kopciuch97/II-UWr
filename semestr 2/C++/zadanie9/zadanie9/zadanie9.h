#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>

std::ostream& comma(std::ostream &Out);
std::ostream& colon(std::ostream &Out);

std::istream & clearline(std::istream & In);

struct manip_ignore
{
	int Size;
	manip_ignore& operator()(int _Size);
};
extern manip_ignore ignore;
std::istream& operator >> (std::istream &In, const manip_ignore &Manip);


struct manip_index
{
	int x, w;
	manip_index& operator()(int _x, int _w);
};
extern manip_index index;

std::ostream& operator<<(std::ostream &Out, const manip_index &Manip);


struct Line
{
	std::string m_Line;
	static int s_Num;
	int m_Num;
	Line();
	
};


std::ostream& operator<<(std::ostream &Out, const Line &Obj);

