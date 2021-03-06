#ifndef UTILITIES_H
#define UTILITIES_H
//////////////////////////////////////////////////////////////
// Utilities.h      - small, generally useful, helper       //
//                    classes and static functions          //
// Version          - 1.2                                   //
// Last Modified    - 08/05/2017                            //
// Language         - Visual C++, Visual Studio 2015        //
// Platform         - MSI GE62 2QD, Core-i7, Windows 10     //
// Author           - Venkata Bharani Krishna Chekuri       //
// e-mail           - bharanikrishna7@gmail.com             //
//////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * This package provides classes StringHelper and Converter and a global
 * function putline().  This class will be extended continuously for
 * awhile to provide convenience functions for general C++ applications.
 *
 * Build Process:
 * --------------
 * Required Files: Utilities.h, Utilities.cpp
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 02/08/2016
 * - first release.
 *
 * ver 1.1 : 05/05/2016
 * - Proper commenting of code.
 * - Updated Test Stub to be easier to understand.
 * - Removed functions : title & test stub display helpers.
 *	> From now on use Title instead of title function.
 *	> Test Stub helper functions are now member functions
 *	  (This has no impact on Utilities class)
 *
 * ver 1.2 : 08/05/2017
 * - Added TimeHelper Class and Converter Class.
 * 
 */
#include <ctime>
#include <string>
#include <vector>  
#include <cctype>
#include <locale>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <WS2tcpip.h>

// Easier to do it here that add "Ws2_32.lib" in linker.
#pragma comment(lib, "Ws2_32.lib")

namespace Utilities
{
	// StringHelper Class
	class StringHelper {
	public:
		static std::vector<std::string> split(const std::string& src);
		static void Title(const std::string& src, char underline = '-');
		static std::string ltrim(std::string &s);
		static std::string rtrim(std::string &s);
		static std::string lrtrim(std::string &s);
		static char * stringToCharArr(std::string str);
	};

	void putline();

	// Timer Class
	class Timer {
	public:
		bool StartClock();
		int  StopClock();
	private:
		int time = 0;
	};

	class TimeHelper {
	private:
		static std::string leftpadZero(int val);
	public:
		static long long int getCurrentTimestamp();
		static std::string timestamptoStrimg(long long int ts);
	};

	template <typename T>
	class Converter
	{
	public:
		static std::string toString(const T& t);
		static T toValue(const std::string& src);
	};

	template <typename T>
	std::string Converter<T>::toString(const T& t)
	{
		std::ostringstream out;
		out << t;
		return out.str();
	}

	template<typename T>
	T Converter<T>::toValue(const std::string& src)
	{
		std::istringstream in(src);
		T t;
		in >> t;
		return t;
	}
}
#endif