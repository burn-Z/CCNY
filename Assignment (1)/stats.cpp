// FILE: stats.cpp
//	CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <limits>	// maximum/minimum double values
#include <cassert>	// assert
#include "stats.h"

using namespace std;

namespace main_savitch_2C
{
	
	statistician::statistician() 
	{
		m_sum = 0;
		m_len = 0;
		m_min = numeric_limits<double>::max();
		m_max = numeric_limits<double>::lowest();
	}

	void statistician::next(double r) 
	{
		m_len+=1;
		m_sum+=r;
		
		if(r < m_min)	m_min = r;
		if(r > m_max)	m_max = r;
	}

	void statistician::reset() 
	{
		m_sum = 0;
		m_len = 0;
		m_min = numeric_limits<double>::max();
		m_max = numeric_limits<double>::lowest();
	}

	double statistician::mean() const
	{
		assert(m_len>0);
		return m_sum/ (1. *m_len);
	}

	double	statistician::minimum() const
	{
		assert(m_len>0);
		return m_min;
	}

	double	statistician::maximum() const
	{
		assert(m_len>0);
		return m_max;
	}


	statistician operator+(const statistician& s1, const statistician& s2)
	{
		statistician s3;
		s3.m_sum = s1.m_sum + s2.m_sum;
		s3.m_len = s1.m_len + s2.m_len;
		s3.m_min = (s1.m_min < s2.m_min)? s1.m_min:s2.m_min;
		s3.m_max = (s1.m_max > s2.m_max)? s1.m_max:s2.m_max;
		
		return s3;
	}
	
	statistician operator*(double scale, const statistician& s)
	{
		statistician ss;
		ss.m_len = s.m_len;
		ss.m_sum = s.m_sum * scale;

		ss.m_max = (scale<0)? (s.m_min*scale):(s.m_max*scale);
		ss.m_min = (scale>0)? (s.m_min*scale):(s.m_max*scale);

		return ss;
	}

	bool operator ==(const statistician& s1, const statistician& s2)
	{
		if(s1.length() == 0 && s2.length() == 0) return true;

		if(s1.length() ==  s2.length() && s1.sum() == s2.sum() && s1.mean() == s2.mean() &&
		   s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()	) return true;

		return false;
	}

}