// FILE: sequence2.cpp
// CLASS IMPLEMENTED: sequence(see header file for documentation)

#include "sequence2.h"
#include <algorithm>
#include <cassert>

using namespace std;
using namespace main_savitch_4;

const sequence::size_type sequence::DEFAULT_CAPACITY;

sequence::sequence(size_type initial_capacity)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
{
	used = 0;
	content = new value_type[initial_capacity];
	this->capacity = initial_capacity;
}

// copy constructor
sequence::sequence(const sequence& source)
//		 Postcondition: source is copied into the sequence
{
	this->content = new value_type[source.capacity];
	this->used = source.used;
	this->capacity = source.capacity;

	copy(source.content, source.content + this->used, this->content);
}

// Destructor
sequence::~sequence( )
//		Postcondion: Deallocates memory used by content
{
	delete[] this->content;
}

void sequence::start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
{
	if(used !=0)
		cursor = 0;
}

void sequence::advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
{
	assert(is_item());
	cursor++;
}

void sequence::insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has 
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
{
	if(capacity > used)
		resize(capacity+1);
	
	if(!is_item())
	{
		for(size_type i = used;i>0;i--)
		{
			*(content+i) = *(content + i-1);  // frees up the first index by moving all items up by 1 index
		}

		*content = entry;
		used++;
		cursor = 0;
	}
	else
	{
		for(size_type i = used;i>cursor;i--)
		{
			*(content+i) = *(content + i-1);	// moves current item and succeeding items up by 1 index
		}

		*(content+cursor) = entry;
		used++;
	}
}

void sequence::attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
{
	if(capacity > used)
		resize(capacity+1);

	if(!is_item())
	{
		*(content + used) = entry;
		used++;
		cursor = used-1;
	}
	else
	{
		for(size_type i = used;i>cursor+1;i--)
		{
			*(content+i) = *(content + i-1);	// moves all items that succeed the current item up by 1 index
		}

		*(content + cursor +1) = entry;
		cursor++;
		used++;
	}
}

void sequence::remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
{
	assert(is_item());

	for(size_type i = cursor+1;i<used;++i)
	{
		*(content + i-1) = *(content+i);	// moves all items succeeding the current item down by 1 index
	}

	used--;
}

void sequence::resize(size_type new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
{
	if(new_capacity == capacity) return;

	if(new_capacity < used)
		new_capacity = used;
	
	value_type* temp_content = new value_type[new_capacity];
	copy(this->content, this->content + this->used, temp_content);

	delete[] this->content;

	this->content = temp_content;
	//delete[] temp_content;
	this->capacity = new_capacity;
	
}

void sequence::operator=(const sequence& source)
//		Postcondition: The source sequence is assigned to the declared sequence
{
	if(this == &source)
		return;

	value_type* temp_content;
	if(this->capacity == source.capacity)
	{
		temp_content = new value_type(source.capacity);
		delete[] this->content;
		this->content = temp_content;
		this->capacity = source.capacity;
	}

	this->used = source.used;
	copy(source.content, source.content + this->used, this->content);
}

sequence::size_type sequence::size( ) const
//     Postcondition: The return value is the number of items on the sequence.
{
	return used;
}

bool sequence::is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
{
	if(cursor >= 0 && cursor < used) return true;

	return false;
}

sequence::value_type sequence::current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
{
	assert(is_item());
	return *(content+cursor);
}