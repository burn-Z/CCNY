// FILE: sequence1.cpp
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)

// The number of items in the sequence is stored in the member variable used

// For an empty sequence, we do not care what is stored in any of data; for
// a non-empty sequence, the items are stored in their sequence order from
// data[0] to data[used-1] , and we don’t care what is stored in the rest of
// data

// If there is a current item, then it lies in data[current_index] ; if there is
// no current item, then current_index equals used .

#include "sequence1.h"
#include <cassert> // provides assert

using namespace main_savitch_3;

const sequence::size_type sequence::CAPACITY;

void sequence::advance()
{
	assert(is_item());
	current_item++;
}

void sequence::insert(const value_type& entry)
{
	assert(used < CAPACITY);

	if(!is_item())
	{
		for(size_type i = used;i>0;i--)
		{
			content[i] = content[i-1];  // frees up the first index by moving all items up by 1 index
		}

		content[0] = entry;
		used++;
		current_item = 0;
	}
	else
	{
		for(size_type i = used;i>current_item;i--)
		{
			content[i] = content[i-1];	// moves current item and succeeding items up by 1 index
		}

		content[current_item] = entry;
		used++;
	}
}

void sequence::attach(const value_type& entry)
{
	assert(used < CAPACITY);

	if(!is_item())
	{
		content[used] = entry;
		used++;
		current_item = used-1;
	}
	else
	{
		for(size_type i = used;i>current_item+1;i--)
		{
			content[i] = content[i-1];	// moves all items that succeed the current item up by 1 index
		}

		content[current_item+1] = entry;
		current_item++;
		used++;
	}
}

void sequence::remove_current()
{
	assert(is_item());

	for(size_type i = current_item+1;i<used;++i)
	{
		content[i-1] = content[i];	// moves all items succeeding the current item down by 1 index
	}

	used--;
}

bool sequence::is_item() const
{
	if(current_item >= 0 && current_item < used) return true;

	return false;
}