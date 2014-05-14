#pragma once
#include <stddef.h>
#include <assert.h>

template <class T>
class RefPtr
{
	T	*t_;

public:
	RefPtr()
		: t_(NULL)
	{}

	RefPtr(T *ip)
		: t_(ip)
	{
		if (t_ != NULL)
			t_->AddRef();
	}

	RefPtr(const RefPtr& rp)
		: t_(rp.t_)
	{
		if (t_ != NULL)
			t_->AddRef();
	}

	~RefPtr()
	{
		if (t_ != NULL)
			t_->Release();
	}

	// Convert to raw pointer
	operator T *() const
	{
		return t_;
	}

	// Reference to the object
	T& operator *() const
	{
		assert(t_ != NULL);
		return *t_;
	}

	// Use in the way of pointer
	T* operator ->() const
	{
		assert(t_ != NULL);
		return t_;
	}

	T** operator &()
	{
		return &t_;
	}

	// Pointer comparation
	bool operator ==(T* t) const
	{
		return t_ == t;
	}

	// Pointer comparation
	bool operator !=(T* t) const
	{
		return t_ != t;
	}

	// Pointer comparation
	bool operator <(T* t) const
	{
		return t_ < t;
	}

	// Assignment
	T* operator =(T* t)
	{
		return assign(t);
	}

	// Assignment
	T* operator =(const RefPtr& rp)
	{
		return assign(rp.t_);
	}

private:
	T* assign(T* t)
	{
		if (t != NULL)
			t->AddRef();
		if (t_ != NULL)
			t_->Release();
		t_ = t;
		return t_;
	}

};
