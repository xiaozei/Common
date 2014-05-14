#include "stdafx.h"
#include "RefCounter.h"

RefCounter::RefCounter(void)
: refCount_(1)
{
}

RefCounter::~RefCounter(void)
{
}

UINT RefCounter::AddRef(void)
{
#if defined(_WIN32) || defined(_WIN64) 
	return ::InterlockedIncrement(reinterpret_cast<LONG*>(&refCount_));
#else
#endif
}

UINT RefCounter::Release(void)
{
#if defined(_WIN32) || defined(_WIN64)
	UINT refCount = ::InterlockedDecrement(reinterpret_cast<LONG*>(&refCount_));
	if (0 == refCount) {
		delete this;
	}
	return refCount;
#else
#endif
}