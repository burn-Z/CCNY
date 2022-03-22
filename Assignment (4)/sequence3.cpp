// FILE: sequence3.cpp
// CLASS IMPLEMENTED: sequence (see sequence3.h for documentation)

/*************************************************************************************************
INVARIANT of the sequence class:
	size_type m_nodes
		keeps track of the number of nodes in the sequence
		>=0

	node* m_head_ptr
		the head pointer of the sequence, not an actual node
		NULL for empty sequence

	node* m_tail_ptr
		the tail pointer of the sequence, not an actual node
		NULL for empty sequence

	node* m_cursor
		points to the current node in the sequence, not an actual node
		NULL for a sequence that has no current item

	node* m_precursor
		points to node before the current item in the sequence, not an actual node
		NULL for empty/one-item sequence, or a sequence that has no current item
*************************************************************************************************/



#include "sequence3.h"
#include <cassert>

using namespace main_savitch_5;

//O(1)
sequence::sequence( )
// Library facilities used: cstdlib
//
// Postcondition: The sequence has been initialized as an empty sequence.
{

	m_nodes = 0;
	m_head_ptr = NULL;
	m_tail_ptr = m_head_ptr;
	m_cursor = NULL;
    m_precursor = NULL;
}

//O(1)
sequence::sequence(const sequence& source)
// Library facilities used: cstdlib, node1.h
{
// Checks for cursor for different copying algorithms
	if(!source.is_item())
	{
		list_copy(source.m_head_ptr,m_head_ptr,m_tail_ptr);
		m_cursor = NULL;
		m_precursor = NULL;
	}
	else if(source.m_cursor == source.m_head_ptr)
	{
		list_copy(source.m_head_ptr,m_head_ptr,m_tail_ptr);
		m_precursor = NULL;
		m_cursor = m_head_ptr;
	}
	else
	{
		// copies sequence by parts to properly copy cursor and precursor
		list_piece(source.m_head_ptr, source.m_cursor,
			m_head_ptr, m_precursor);
		list_piece(source.m_cursor, source.m_tail_ptr->link(),
			m_cursor, m_tail_ptr);
		
		// merges the copied segments
		m_precursor->set_link(m_cursor);
	}

	
	this->m_nodes = source.m_nodes;
}

//O(1)
sequence::~sequence( )
// Library facilities used: cstdlib, node1.h
// empties the sequence and releases the used memories
{
	list_clear(m_head_ptr);
	m_cursor = NULL;
	m_precursor = NULL;
	m_tail_ptr = NULL;
	m_nodes = 0;
}

//O(1)
void sequence::start( )
// Library facilities used: cstdlib
// initiates sequence iteration
{
	m_cursor = m_head_ptr;
	m_precursor = NULL;
}

//O(1)
void sequence::advance( )
// Library facilities used: cassert, node1.h
// iterates through sequence
{
	assert(is_item());

	m_precursor = m_cursor;			//moves cursor to following item
	m_cursor = m_cursor->link();	// moves cursor to following item
}

//O(n)
void sequence::insert(const value_type& entry)
// Library facilities used: node1.h
{
	// if cursor exist then there are two special cases for insertion
	if(is_item())
	{
		if(m_cursor == m_head_ptr)
		{
			list_head_insert(m_head_ptr, entry);
			m_cursor = m_head_ptr;
		}
		else
		{
			list_insert(m_precursor,entry);
			m_cursor = m_precursor->link();
		}
	}
	// two more if it doesnt
	else
	{
		// creates head for empty sequence
		if(m_nodes == 0)
		{
			m_head_ptr = new node(entry);
			m_tail_ptr = m_head_ptr;
		}
		// new head for non empty sequence
		else
		{
			list_head_insert(m_head_ptr,entry);
		}
		m_cursor = m_head_ptr;
	}

	++m_nodes;
}

//O(n)
void sequence::attach(const value_type& entry)
// Library facilities used: node1.h
{
	if(is_item())
	{
		list_insert(m_cursor,entry);
		// tail moves if item is added at the end of the list
		if(m_cursor == m_tail_ptr)
		{
			m_tail_ptr = m_tail_ptr->link();
		}
		//handles precursor and cursor iteration
		advance();
	}
	// two cases for NULL cursor
	else
	{
		if(m_nodes == 0)
		{
			m_head_ptr = new node(entry);
			m_tail_ptr = m_head_ptr;
			m_cursor = m_tail_ptr;
		}
		else
		{
			m_precursor = m_tail_ptr;
			list_insert(m_tail_ptr,entry);
			m_tail_ptr = m_tail_ptr->link();
			m_cursor = m_tail_ptr;
		}
	}

	++m_nodes;
}

//O(n)
void sequence::remove_current( )
// Library facilities used: cassert, node1.h, cstdlib
// handles current item removal by cases
{
	assert(is_item());
	
	if(m_cursor == m_head_ptr) {
		list_head_remove(m_head_ptr);
		m_cursor = m_head_ptr;
	}
	else if(m_cursor == m_tail_ptr)
	{
		delete m_tail_ptr;
		m_precursor->set_link(NULL);
		m_tail_ptr = m_precursor;
		m_cursor = NULL;
	}
	else
	{
		list_remove(m_precursor);
		m_cursor = m_precursor->link();
	}
	
	--m_nodes;
}

//O(1)
void sequence::operator =(const sequence& source)
// Library facilities used: node1.h, cstdlib
{
	// check for duplicate sequences
	if(this == &source)
		return;

	// frees current sequence memory
	list_clear(this->m_head_ptr);

	// see copy-constructor
	if(!source.is_item())
	{
		list_copy(source.m_head_ptr,m_head_ptr,m_tail_ptr);
		m_cursor = NULL;
		m_precursor = NULL;
	}
	else if(source.m_cursor == source.m_head_ptr)
	{
		list_copy(source.m_head_ptr,m_head_ptr,m_tail_ptr);
		m_precursor = NULL;
		m_cursor = m_head_ptr;
	}
	else
	{
		// copies sequence by parts to properly copy cursor and precursor
		list_piece(source.m_head_ptr, source.m_cursor,
			m_head_ptr, m_precursor);
		list_piece(source.m_cursor, source.m_tail_ptr->link(),
			m_cursor, m_tail_ptr);
		
		// merges the copied segments
		m_precursor->set_link(m_cursor);
	}

	this->m_nodes = source.m_nodes;
}

//O(1)
size_t sequence::size( ) const
{
	return m_nodes;
}

//O(1)
bool sequence::is_item( ) const
// Library facilities used: cstdlib
// checks if there is an item at the cursor
{
	if(m_cursor == NULL) return false;

	return true;
}

//O(1)
sequence::value_type sequence::current( ) const
// Library facilities used: cassert, node1.h
{
	assert(is_item());

	return m_cursor->data();
}