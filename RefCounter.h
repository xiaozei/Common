#pragma once

class RefCounter
{
public:
	UINT AddRef(void);

	UINT Release(void);

	virtual UINT GetRefCount() { return refCount_; }

protected:
	RefCounter(void);

	virtual ~RefCounter(void);

private:
	UINT refCount_;
};



